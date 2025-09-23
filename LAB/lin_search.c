#include <stdio.h>
#include "function2.c"
int main()
{
	int arr[50],size;
	printf("Enter the size: ");
	scanf("%d",&size);
	get_array(arr,size);
	printf("The array is : \n");
	print_array(arr,size);
	printf("\n");
	int key;
	printf("Enter the key value to be searched in the  array : ");
	scanf("%d",&key);
	int pos=lin_search(arr,size,key);
	if(pos!=-1)
		printf("The position of the key element %d is %d\n",key,pos);
	else
		printf("The key element %d is not found in the array\n",key);

	return 0;
}
