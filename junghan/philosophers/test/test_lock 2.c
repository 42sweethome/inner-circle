#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
// 뮤텍스 객체 선언
pthread_mutex_t mutex_lock;
 
int g_count = 0;  // 쓰레드 공유자원.
 
void *t_function(void *data)
{
    int i;
    char* thread_name = (char*)data;
    // critical section
    g_count = 0;   // 쓰레드마다 0부터 시작.
    for (i = 0; i < 3; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // 쓰레드 공유자원, 1증가.
        sleep(1);
    }
}

int main()
{
    pthread_t p_thread1, p_thread2;
    int status;
 
    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");
 
    pthread_join(p_thread1, (void *)&status);
    pthread_join(p_thread2, (void *)&status);
	return (0);
}
 
