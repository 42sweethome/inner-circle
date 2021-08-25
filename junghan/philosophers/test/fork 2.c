#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int pid;

    pid = fork();
    if (pid > 0)
    {
        printf("부모 프로세스 %d : %d\n", getpid(), pid);
       // pause();
    }
    else if (pid == 0)
    {
        printf("자식 프로세스 %d\n", getpid());
       // pause();
    }
    else if (pid == -1)
    {
        perror("fork error : ");
        exit(0);
    }
}
