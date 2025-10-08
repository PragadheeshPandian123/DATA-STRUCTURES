#include <stdio.h>

#define SIZE 3

int main() {
    int matrix[SIZE][SIZE], rotated[SIZE][SIZE];
    int i, j;

    printf("Enter elements of %dx%d matrix:\n", SIZE, SIZE);
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            rotated[j][SIZE - 1 - i] = matrix[i][j];
        }
    }

    printf("\nOriginal Matrix:\n");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nRotated Matrix (90 degrees clockwise):\n");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%4d", rotated[i][j]);
        }
        printf("\n");
    }

    return 0;
}
