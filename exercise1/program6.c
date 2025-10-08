# include <stdio.h>
# include <stdlib.h>
int main()
{
	printf("Dynamic memory allocation for arrays: \n");
	int *ptr;
	ptr=(int *)malloc(sizeof(int)*5);
	printf("Pointers with arrays : \n");
	printf("Enter array elements : \n");
	for(int i=0;i<5;i++)
	{
		scanf("%d",(ptr+i));
	}

	printf("The array is : ");
	for(int i=0;i<5;i++)
	{
		printf("%d ",*(ptr+i));
	}
	printf("\n");
	printf("Pointer Arithmetic : \n");
	printf("2nd element in array is :%d \n",*(++ptr));
	printf("Back to 1st element in array is : %d \n",*(--ptr));
	int *ptr2=ptr+4;
	printf("The number of elements in array is : %ld \n",(ptr2-ptr)+1);

	return 0;
}

	
