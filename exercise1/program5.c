#include <stdio.h>
#include <string.h>

void makeUppercase_pass_by_reference(char str[]) {
    for(int i = 0; str[i]!='\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;  
    }
}
void makeUppercase_pass_by_value(char ch){
	if(ch>='a' && ch<='z')
		ch-=32;
	printf("%c",ch);
}
int main() {
    char name[50];
    printf("\nEnter a string: ");
	scanf("%[^\n]s",name);
	printf("\nEntered string is : %s\n",name);
	printf("Inside function using pass by value : \n");
	for(int i=0; name[i]!='\0';i++)
	{
		makeUppercase_pass_by_value(name[i]);
	}
	printf("\n");
	printf("After pass by value : %s",name);
    makeUppercase_pass_by_reference(name);  
	printf("\nAfter pass by reference.\n");
    printf("Uppercase version: %s\n", name);

    return 0;
}
