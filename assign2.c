#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,z,a,b;
	printf("Enter MAXIMUM number till where you want to RUN\n");
	scanf("%d",&b);
	printf("Enter the number\n");
	scanf("%d",&a);
	
	for(i=1;i<=(b/a);i++)
	{
		z=a*i;
		printf("%d\n",z);
	}
}
