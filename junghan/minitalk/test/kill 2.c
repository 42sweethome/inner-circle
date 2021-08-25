#include <sys/types.h>

#include <signal.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int pid;
    int sig_num;

    // 아규먼트로 pid 번호와 
    // 전송할 signal 번호를 받아들여서 
    // 이를 해당 pid 로 보낸다. 
    pid = atoi(argv[1]);
    sig_num = atoi(argv[2]);

    kill(pid, sig_num);
}
	
