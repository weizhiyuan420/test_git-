#include<pthread.h>
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
static int counter = 0;
#define LOOPs 10000000
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static void * thread(void * noused)
{
	int i;
	for(i=0;i<LOOPs;i++)
	{
		pthread_mutex_lock(&mutex);
		++counter;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}
int main(void)
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread,NULL);
	pthread_create(&t2,NULL,thread,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Counter is:%d by threads\n",counter);
	return 0;
}
