#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



static int i;
pthread_mutex_t lock;



void *print_even(void *i)
{

int a = *(int*)i;

for (int x=1; x<=a; x++)



if(x%2==0)
{

pthread_mutex_lock(&lock);
printf("EVEN : %d\n",x);
pthread_mutex_unlock(&lock);
sleep(1);



}



return 0;
}



void *print_odd(void *i)
{

int a = *(int*) i;
for (int x=1; x<=a; x++)
if(x%2!=0)
{

pthread_mutex_lock(&lock);
printf("ODD : %d\n",x);
pthread_mutex_unlock(&lock);
sleep(1);
}



return 0;
}



int main(void)
{



pthread_mutex_init(&lock, 0);
pthread_t thread1, thread2;
printf("Enter a number: ");
scanf("%d",&i);
pthread_create(&thread2, NULL, print_even, (void *)&i);
pthread_create(&thread1, NULL, print_odd, (void *)&i);

pthread_join(thread2, NULL);
pthread_join(thread1, NULL);
pthread_mutex_destroy(&lock);
return 0;
}
