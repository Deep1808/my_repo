#include<stdio.h>
#include<stdlib.h>

main()
{
//int arr_size = 100;
int *arr = malloc(sizeof(int) * 100);

for(int i=0; i<100; i++)
{
	arr[i]=i;
	printf("\nArray[%d]= %d",i,arr[i]);
}

realloc(arr,40);
//free(arr);
return 0;

}
