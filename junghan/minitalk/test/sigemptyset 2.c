#include <signal.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdio.h> 

void sig_int(int signo);
void sig_usr(int signo);

int main()
{
    int i = 0;
    struct sigaction intsig, usrsig;

    usrsig.sa_handler = sig_usr;
    sigemptyset(&usrsig.sa_mask);
    usrsig.sa_flags = 0;

    intsig.sa_handler = sig_int;
    sigemptyset(&intsig.sa_mask);
    intsig.sa_flags = 0;

    if (sigaction(SIGINT, &intsig, 0) == -1)
    {
        printf ("signal(SIGINT) error");
        return -1;
    }    

    if (sigaction(SIGUSR2, &usrsig, 0) == -1)
    {
        printf ("signal(SIGUSR2) error");
        return -1;
    }    

    while(1)
    {
        printf("%d\n", i);
        i++;
        sleep(1);
    }
}

void sig_int(int signo)
{
    sigset_t sigset, oldset;

    sigfillset(&sigset);
    if (sigprocmask(SIG_BLOCK, &sigset, &oldset) < 0)
    {
        printf("sigprocmask %d error \n", signo);
    }
    fprintf(stderr, "SIGINT !!!!\n");
    sleep(5);
}

void sig_usr(int signo)
{
    printf("sig_usr2\n");
}
