#include <stdio.h>
#include <string.h>
int main()
{
	char str[50],rev[50];
	printf("Enter a string : ");
	scanf("%[^\n]s",str);
	int i,j;
	for(i=strlen(str)-1,j=0;i>=0;i--,j++)
	{
		rev[j]=str[i];
	}
	rev[j]='\0';
	printf("Original String : %s \n",str);
	printf("Reversed String : %s \n",rev);
	if(strcmp(str,rev)==0)
		printf("Palindrome.\n");
	else
		printf("Not a Palindrome.\n");
	return 0;
}
