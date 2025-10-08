#include <stdio.h>
#include <string.h>

int main() { 
    char words[5][20];  
    int i, maxLen = 0, index = 0;

    printf("Enter 5 words:\n");
    for(i = 0; i < 5; i++) {
        scanf("%s", words[i]);
        getchar();
    }


    for(i = 0; i < 5; i++) {
        int len = strlen(words[i]);
        if(len > maxLen) {
            maxLen = len;
            index = i;
        }
    }

    printf("\nThe longest word is: %s\n", words[index]);
    printf("Length: %d\n", maxLen);

    return 0;
}
