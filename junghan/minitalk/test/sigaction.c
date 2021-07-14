#include <signal.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdio.h> 

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler(int signo)
{
	printf("C?\n");
	printf("again?\n");
	sigaction(SIGINT, &act_old, NULL);
}

int main(void)
{
	int i;
	act_new.sa_handler=sigint_handler; //시그널 핸들러 지정
	sigemptyset(&act_new.sa_mask); //시그널 처리 중 블록될 시그널은 없음

	//SIGINT를 지정하면서 act_old에 이전 정보를 구합니다.
	sigaction(SIGINT, &act_new, &act_old);
	i = 0;
	while(1)
	{
		i++;
		printf("haha %d\n", i);
		sleep(1);
	}
}     
