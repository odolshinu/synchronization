#include<stdio.h>
#include<pthread.h>

typedef struct {
	int val;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
}semaphore;

semaphore s;

void down(semaphore *s)
{
	pthread_mutex_lock(&(s->mutex));
	while (s->val == 0) {
		pthread_cond_wait(&(s->cond), &(s->mutex));
	}
	s->val--;
	pthread_mutex_unlock(&(s->mutex));
}

void up(semaphore *s)
	{
	pthread_mutex_lock(&(s->mutex));
	s->val++;
	pthread_cond_broadcast(&(s->cond));
	pthread_mutex_unlock(&(s->mutex));
}

void init(semaphore *s)
{
	s->val = 0;
}

main()
{
	init(&s);
	up(&s);
	up(&s);
	printf("%d\n", s.val);
	down(&s);
	down(&s);
	printf("%d\n", s.val);
}
