#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static int i;
static int x;

void *print_t1(void *i)
	{
		int a = *(int*)i;
		for(x=1; x<=a; x+3)
	{
	printf("Thread 1 : %d\n",x);
	x++;
	sleep(1);
}
	return 0;
}

void *print_t2(void *i)
{
	int a = *(int*)i;
	for(x=2; x<=a; x+3)
	{
		printf("Thread 2 : %d\n",x);
		x++;
		sleep(1);
	}
	return 0;
}

void *print_t3(void *i)
{
	int a = *(int*)i;
	for(x=3; x<=a; x+3)
	{
		printf("Thread 3 : %d\n",x);
		x++;
		sleep(1);
	}
return 0;
}

int main(void)
{

pthread_t thread1, thread2, thread3;
printf("Enter a number upto which you want to print: ");
scanf("%d",&i);
pthread_create(&thread3, NULL, print_t3, (void *)&i);
pthread_create(&thread2, NULL, print_t2, (void *)&i);
pthread_create(&thread1, NULL, print_t1, (void *)&i);
pthread_join(thread3, NULL);
pthread_join(thread2, NULL);
pthread_join(thread1, NULL);
return 0;
}

