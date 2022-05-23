#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
struct num
{
	int a,b;
};

void threadfun(void *i)
{ 
	struct num *n;
	n=(struct num *) i; 
	int x,y,z;
	x=n->a;
	y=n->b;
	for(int j=1;j<=(x/y);j++)
	{
		int z=y*j;
		printf("%d\n",z);
	}
}
void main()
{ 
	pthread_t t1; 
	int i,x,y;
	printf("Enter MAXIMUM number till where you want to RUN\n");
	scanf("%d",&x);
	printf("Enter the number\n");
	scanf("%d",&y); 
	struct num n1;

	n1.a=x;
	n1.b=y;

	pthread_create(&t1,NULL,threadfun,(void *)&n1);
	pthread_join(t1,NULL);
}


