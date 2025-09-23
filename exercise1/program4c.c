#include <stdio.h>
#include <string.h>
#include <ctype.h>

int areAnagrams(char str1[], char str2[]) {
    int count[26] = {0};
    int i;

    for(i = 0; str1[i] != '\0'; i++) {
        if(isalpha(str1[i]))
            count[tolower(str1[i]) - 'a']++;
    }
    
    for(i = 0; str2[i] != '\0'; i++) {
        if(isalpha(str2[i]))
            count[tolower(str2[i]) - 'a']--;
    }

    for(i = 0; i < 26; i++) {
        if(count[i] != 0)
            return 0; 
    }

    return 1; 
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    if(areAnagrams(str1, str2))
        printf("'%s' and '%s' are Anagrams.\n", str1, str2);
    else
        printf("'%s' and '%s' are NOT Anagrams.\n", str1, str2);

    return 0;
}
