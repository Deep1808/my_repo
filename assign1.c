#include<stdio.h>
#include<pthread.h>
#include<ctype.h>

void *threadfun(void *i){
	char a = *(char *) i;
	printf("Character value %c\n",a);
	char  c,z;
	if(c>64 && c<120)
	{
		if(a>97)
		{
		for(c='a';c<=a;c++)
		{
			printf("%c\n",c);
		}
		}
		else{
		for( c='A';c<=a;c++)
		{
			printf("%c\n",c);
		}
		
		}
	}
	else
	{
		printf("Enter somthing in the range !!");
	}
}


int main()
{
	pthread_t t1;

	char i;
	printf("Enter a character: ");
	scanf("%c",&i);
	pthread_create(&t1,NULL,threadfun,(void *)&i);
	pthread_join(t1,NULL);
	return 0;
	
}
