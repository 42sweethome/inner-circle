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

 
   pthread_mutex_lock(&mutex_lock);

    // critical section
    g_count = 0;   // 쓰레드마다 0부터 시작.
    for (i = 0; i < 3; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;  // 쓰레드 공유자원
        sleep(1);
    }

    pthread_mutex_unlock(&mutex_lock);
}

int main()
{
    pthread_t p_thread1, p_thread2;
    int status;
	int thr_id;
    // 뮤텍스 객체 초기화, 기본 특성으로 초기화 했음

    pthread_mutex_init(&mutex_lock, NULL);
    thr_id =pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }
    thr_id =pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }
    pthread_join(p_thread1, (void *)&status);
    pthread_join(p_thread2, (void *)&status);
}


