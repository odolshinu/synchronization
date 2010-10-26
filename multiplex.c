/*A sample program to demonstarte Multiplex in semaphore*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t lock;
int count = 0;

void *fun1(void *arg)
{
	sem_wait(&lock);
	sleep(1);
	count = count + 1;
	printf("In fun1 : %d\n",count);
	sem_post(&lock);
}

void *fun2(void *arg)
{
	sem_wait(&lock);
	sleep(1);
	count = count + 1;
	printf("In fun2 : %d\n",count);
	sem_post(&lock);
}

void *fun3(void *arg)
{
	sem_wait(&lock);
	sleep(1);
	count = count + 1;
	printf("In fun3 : %d\n",count);
	sem_post(&lock);
}

main()
{
	int n = 3, i;
	pthread_t t[n];
	sem_init(&lock, 0, 2);
	pthread_create(&t[0], 0, fun1, 0);
	pthread_create(&t[1], 0, fun2, 0);
	pthread_create(&t[2], 0, fun3, 0);

	pthread_join(t[0], 0);
	pthread_join(t[1], 0);
	pthread_join(t[2], 0);
}
