#include<stdio.h>

void main()
{
	int a[5]={1,2,3,4,5};
	int i,sum;
	int *p;
	p= &a[0];

for(i=0;i<=5;i++)
{
	sum= sum + *p;
	p++;
}
printf("Sum of Elements is:%d\n",sum);
}
