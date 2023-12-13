#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(){
	int fd_in = open("/dev/pts/7",O_RDONLY);
	if(fd_in == -1){
		printf("error opening dev");
		return 1;
	}

	int fd_out = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if(fd_out == -1){
		printf("error opening txt file");
		return 1;
	}

	char buf[20];
	ssize_t bytes_read;

	while ((bytes_read = read(fd_in, buf, sizeof(buf))) > 0) {
		buf[bytes_read] = '\0';

		if (bytes_read >= 4 && buf[0] == 'E' && buf[1] == 'N' && buf[2] == 'D' && buf[3] == '\n'){
			break;
		}

		ssize_t bytes_written = write(fd_out,buf,bytes_read);
		if (bytes_written == -1) {
			close(fd_in);
			close(fd_out);
			return 1;
		}
	}

	close(fd_in);
	close(fd_out);
	return 0;
}
