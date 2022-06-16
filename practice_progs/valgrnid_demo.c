#include<stdio.h>
#include<stdlib.h>

main()
{
int arr_size = 100;
int *arr = malloc(sizeof(int) * arr_size);
#if 1

for(int i=0; i<arr_size; i++)
{
	arr[i]=i;
	//printf("\nArray[%d]= %d",i,arr[i]);
}
#endif

free(arr);
return 0;

}
