#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        int row = 0;
        int column = 0;
        row = atoi(argv[1]);
        column = atoi(argv[2]);

        int *A = (int *)malloc((row * column) * sizeof(int));
        int i, j;

        printf("Enter the matrix elements:\n");
        for (i = 0; i < row; i++)
        {
                for (j = 0; j < column; j++)
                {
                        printf("A[%d, %d] = ", i, j);
                        scanf("%d", A + i * column + j);
                }
                printf("\n");
        }

        int n = 0;
        printf("Enter a number:");
        scanf("%d", &n);

        for (int i = 0; i < row; ++i)
        {
                pid_t pid = fork();

                if (pid == -1)
                { // not able to create child
                        printf("parent PID %d => \n", getpid());

                        //      for (j = 0; j < column; j++){
                        //              *(A + i * column + j) = n * (*(A + i * column + j));
                        //              printf("%d * A[%d,%d] %d\n", n, i, j, *(A + i * column + j));
                        //      }
                }

                else if (pid == 0)
                { // child
                        printf("childe %d PID: %d\n", i, getpid());
                        exit(0);
                        //      for (j = 0; j < column; j++) {
                        //      *(A + i * column + j) = n * (*(A + i * column + j));
                        //      printf("%d * A[%d,%d] = %d\n", n, i, j, *(A + i * column + j));
                }
        }
        // the problem was that we were doing the math in both parent and child
        // to fix the final martix all we needed to do was perform the mutipling in the parent process

        if (getpid() > 0)
        {
                for (int i = 0; i < row; ++i)
                {
                        for (int j = 0; j < column; j++)
                        {
                                *(A + i * column + j) = n * (*(A + i * column + j));
                        }
                }
                wait(0);
        }

        printf("Final matrix elements:\n");
        for (i = 0; i < row; i++)
        {
                for (i = 0; i < row; i++)
                {
                        for (j = 0; j < column; j++)
                        {
                                printf("A[%d,%d] = %d\n", i, j, *(A + i * column + j));
                        }
                        printf("\n");
                }
                exit(0);
        }
}