/*A simple program to demonstrate Rendezvous in semaphore*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t a1, b1;

void *fun1(void *arg)
{
	printf("a1\n");
	sem_post(&a1);
	sem_wait(&b1);
	printf("a2\n");
}

void *fun2(void *arg)
{
	printf("b1\n");
	sem_post(&b1);
	sem_wait(&a1);
	printf("b2\n");
}

main()
{
	pthread_t t1, t2;
	sem_init(&a1, 0, 0);
	sem_init(&b1, 0, 0);
	pthread_create(&t1, 0, fun1, 0);
	pthread_create(&t2, 0, fun2, 0);

	pthread_join(t1, 0);
	pthread_join(t2, 0);
}
