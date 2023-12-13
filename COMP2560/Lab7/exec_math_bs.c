#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	printf("exec_math_bootstrap pid:%d\n", getpid());
	
	char operation = argv[1][0];
	int operand1 = atoi(argv[2]);
	int operand2 = atoi(argv[3]);	
	
	char program[1024];
	sprintf(program,"#include <stdio.h>\n"
			"#include <stdlib.h>\n"
			"#include <unistd.h>\n"
			"int main() {\n"
			"int operand1 = %d;\n"
			"int operand2 = %d;\n"
			"int result;\n"
			"switch('%c'){\n"
				"case '+': result = operand1 + operand2; break;\n"	
				"case '-': result = operand1 - operand2; break;\n"
				"case '*': result = operand1 * operand2; break;\n"
				"case '/': result = operand1 / operand2; break;\n"
				"default: printf(\"Invalid operation\\n\"); return 1;\n"
			"}\n"
			"printf(\"Result: %d %c %d = %d\\n\", operand1, '%c', operand2, result);\n"
			"return 0;\n"
			"}\n",operand1, operand2, operation, operand1, operation, operand2,
			(operation == '+') ? (operand1 + operand2) :
			(operation == '-') ? (operand1 - operand2) :
			(operation == '*') ? (operand1 * operand2) :
			(operation == '/') ? (operand1 / operand2) : 0), operation;

	int fd = creat("./math.c", O_CREAT | S_IRUSR | S_IWUSR);
	printf("fd for math.c file:%d\n", fd);
	write(fd, program, strlen(program));

	close(fd);
	
	pid_t compile_pid = fork();
 	if (compile_pid == 0) {
	execlp("cc", "cc", "./math.c", "-o", "./math_executable", NULL);
	perror("execlp");
	exit(EXIT_FAILURE);
	} else {
	waitpid(compile_pid, NULL, 0);
	}

	char executable_path[] = "./math_executable";

	if (fd == -1) {
	   perror("open");
	   exit(EXIT_FAILURE);
	}
	int pipefd[2];
	pid_t child_pid;

	if (pipe(pipefd) == -1) {
	perror("pipe");
	exit(EXIT_FAILURE);
	}
 
	child_pid = fork();

	    if (child_pid == -1) {
		perror("fork");
	        exit(EXIT_FAILURE);
	    }

	    if (child_pid == 0) { // Child process
		close(pipefd[1]);
	        dup2(pipefd[0], STDIN_FILENO);
	        // Execute the compiled program
		char *args[] = {executable_path, NULL};
		execve(executable_path, args, NULL);
		perror("fexecve");
		exit(EXIT_FAILURE);
	    } else { // Parent proces
		close(pipefd[0]); 
		write(pipefd[1], "./math", strlen("./math"));
		close(pipefd[1]); 
		waitpid(child_pid, NULL, 0); // Wait for the child process to finish
	    }
	return 0;
}
