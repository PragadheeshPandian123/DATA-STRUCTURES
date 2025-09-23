#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
	int num_array[10],even=0,odd=0;
	srand(time(NULL));
	for(int i=0;i<10;i++)
	{
		num_array[i]=(rand()%100)+1;
	}
	printf("The random array is : \n");
	for(int i=0;i<10;i++)
        {
                printf("%d ",num_array[i]);
		if(num_array[i]%2==0)
			even++;
		else
			odd++;
        }
	printf("\n");
	printf("The number of odd elements is : %d\n",odd);
	printf("The number of even elements is : %d\n",even);

	return 0;
}



