/*A sample program to demonstrate Signaling*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem;

void *fun1(void *arg)
{
	printf("in fun1\n");
	sem_post(&sem);
}

void *fun2(void *arg)
{
	sem_wait(&sem);
	printf("in fun2\n");
}

main()
{
	pthread_t t1, t2;
	sem_init(&sem, 0, 0);
	pthread_create(&t1, 0, fun1, 0);
	pthread_create(&t2, 0, fun2, 0);

	pthread_join(t1, 0);
	pthread_join(t2, 0);
}
