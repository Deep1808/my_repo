// C program to demonstrate working of Semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
	//wait
	
	int n1=fork();
	int n2=fork();
	//pid_t pid_1;
	printf("hiiiiiiiiii------------ %d ",n1);

	printf("\nEntered..\n");
	sem_wait(&mutex);
	//critical section
	//sleep(4);
	printf("IN CRITICAL SECTION !!");
	
	//signal
	sem_post(&mutex);
	//pid_t pid_2;
	printf("----------- %d",n2);

	printf("\nJust Exiting...\n");
	
	
}


int main()
{
	sem_init(&mutex, 0, 1);
	pthread_t t1,t2;
	sleep(2);
	pthread_create(&t2,NULL,thread,NULL);
	
	//pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	return 0;
}

