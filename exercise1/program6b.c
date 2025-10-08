#include <stdio.h>
#include <string.h>

int revealSecret(const char *secret, char *display, char guess) {
    const char *s = secret;
    char *d = display;
    int flag=0;
    while (*s != '\0') {
        if (*s == guess)
        {
            flag=1;
            *d = *s;
        }
        s++;
        d++;
    }
    return flag;
}

int main() {
    char secret[] = "pointer";
    char display[] = "_______";
    char guess;
    int attempts = 5;

    printf("Guess the secret word (7 letters). You have %d attempts!\n", attempts);

    while (attempts!=0) {
        printf("\nCurrent: %s\n", display);
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        if(revealSecret(secret, display, guess)==0)
        {
            attempts--;
        }

        if (strcmp(secret, display) == 0) {
            printf("You guessed the word: %s\n", secret);
            return 0;
        }
    }

    printf("\n Out of attempts! The word was: %s\n", secret);
    return 0;
}
