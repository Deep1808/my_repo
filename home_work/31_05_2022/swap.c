#include<stdio.h>

void main()
{
	int a=10,b=20,temp;
	int *p,*q;
	p=&a;
	q=&b;

	printf("Before a:%d	Before b:%d\n",a,b);
	
	temp=*q;
	*q=*p;
	*p=temp;

	printf("After A:%d	After B:%d\n",*p,*q);
}
