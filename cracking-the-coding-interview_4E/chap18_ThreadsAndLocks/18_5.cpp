/*
 * 18_5.cpp
 *
 *  Created on: 2013-5-19
 *      Author: beet
 */

// Execute A, B, C threads in order

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t threadCondMutex;
pthread_cond_t threadACond;
pthread_cond_t threadBCond;
pthread_cond_t threadCCond;

void* threadA(void* para)
{
	while(true)
	{
		pthread_mutex_lock( &threadCondMutex );
		pthread_cond_wait( &threadCCond, &threadCondMutex );

		printf("Executing A...\n"); fflush(stdout);
		sleep(1);

		pthread_cond_signal( &threadACond );
		pthread_mutex_unlock( &threadCondMutex );
	}
	return NULL;
}

void* threadB(void* para)
{
	while(true)
	{
		pthread_mutex_lock( &threadCondMutex );
		pthread_cond_wait( &threadACond, &threadCondMutex );

		printf("Executing B...\n"); fflush(stdout);
		sleep(1);

		pthread_cond_signal( &threadBCond );
		pthread_mutex_unlock( &threadCondMutex );
	}
	return NULL;
}

void* threadC(void* para)
{
	while(true)
	{
		pthread_mutex_lock( &threadCondMutex );
		pthread_cond_wait( &threadBCond, &threadCondMutex );

		printf("Executing C...\n"); fflush(stdout);
		sleep(1);

		pthread_cond_signal( &threadCCond );
		pthread_mutex_unlock( &threadCondMutex );
	}
	return NULL;
}

int main()
{
	pthread_mutex_init( &threadCondMutex, NULL );
	pthread_cond_init( &threadACond, NULL );
	pthread_cond_init( &threadBCond, NULL );
	pthread_cond_init( &threadCCond, NULL );

	pthread_t pid;
	pthread_create(&pid, NULL, threadA, NULL);
	pthread_create(&pid, NULL, threadB, NULL);
	pthread_create(&pid, NULL, threadC, NULL);

	pthread_cond_signal( &threadCCond );

	// forever loop
	while(true)
		sleep(1000);

	return 0;
}
