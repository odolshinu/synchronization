/*A sample program to demonstrate Barriers in semaphore*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex, barrier;
int count = 0, n;

void *fun1(void *arg)
{
	sem_wait(&mutex);
	printf("a1\n");
	count++;
	sem_post(&mutex);
	if (count == n) {
		sem_post(&barrier);
	}
	sem_wait(&barrier);
	printf("a2\n");
	sem_post(&barrier);
}

void *fun2(void *arg)
{
	sem_wait(&mutex);
	printf("b1\n");
	count++;
	sem_post(&mutex);
	if (count == n) {
		sem_post(&barrier);
	}
	sem_wait(&barrier);
	printf("b2\n");
	sem_post(&barrier);
}

void *fun3(void *arg)
{
	sem_wait(&mutex);
	printf("c1\n");
	count++;
	sem_post(&mutex);
	if (count == n) {
		sem_post(&barrier);
	}
	sem_wait(&barrier);
	printf("c2\n");
	sem_post(&barrier);
}

void *fun4(void *arg)
{
	sem_wait(&mutex);
	printf("d1\n");
	count++;
	sem_post(&mutex);
	if (count == n) {
		sem_post(&barrier);
	}
	sem_wait(&barrier);
	printf("d2\n");
	sem_post(&barrier);
}

main()
{
	n = 4;
	pthread_t t[n];
	sem_init(&mutex, 0, 1);
	sem_init(&barrier, 0, 0);

	pthread_create(&t[0], 0, fun1, 0);
	pthread_create(&t[1], 0, fun2, 0);
	pthread_create(&t[2], 0, fun3, 0);
	pthread_create(&t[3], 0, fun4, 0);

	pthread_join(t[0], 0);
	pthread_join(t[1], 0);
	pthread_join(t[2], 0);
	pthread_join(t[3], 0);
}
