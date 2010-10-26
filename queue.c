/*Implementation of Queue using semaphore*/
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t follower, leader, mutex, rendezvous;
int leaders = 0, followers = 0;

void *lead(void *arg)
{
	sem_wait(&mutex);
	if (followers > 0) {
		followers--;
		sem_post(&leader);
	} else {
		leaders++;
		sem_post(&mutex);
		sem_wait(&follower);
	}
	printf("leader dancing\n");
	sem_wait(&rendezvous);
	sem_post(&mutex);
}

void *follow(void *arg)
{
	sem_wait(&mutex);
	if (leaders > 0) {
		leaders--;
		sem_post(&follower);
	} else {
		followers++;
		sem_post(&mutex);
		sem_wait(&leader);
	}
	printf("follower dancing\n");
	sem_post(&rendezvous);
}

main()
{
	pthread_t t1, t2, t3, t4, t5;
	sem_init(&follower, 0, 0);
	sem_init(&leader, 0, 0);
	sem_init(&mutex, 0, 1);
	sem_init(&rendezvous, 0, 1);

	pthread_create(&t1, 0, lead, 0);
	pthread_create(&t3, 0, lead, 0);
	pthread_create(&t4, 0, lead, 0);
	pthread_create(&t5, 0, follow, 0);
	pthread_create(&t2, 0, follow, 0);

	pthread_join(t1, 0);
	pthread_join(t2, 0);
	pthread_join(t3, 0);
	pthread_join(t5, 0);
	pthread_join(t4, 0);
}
