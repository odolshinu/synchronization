/*A sample program to demonstrate the use of semaphore as Mutex*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t lock;
int count = 1;

void *fun1(void *arg)
{
	sem_wait(&lock);
	count = count + 1;
	printf("In fun1 : %d\n",count);
	sem_post(&lock);
}

void *fun2(void *arg)
{
	sem_wait(&lock);
	count = count + 1;
	printf("In fun2 : %d\n",count);
	sem_post(&lock);
}

main()
{
	pthread_t t1, t2;
	sem_init(&lock, 0, 1);
	pthread_create(&t1, 0, fun1, 0);
	pthread_create(&t2, 0, fun2, 0);

	pthread_join(t1, 0);
	pthread_join(t2, 0);
}
