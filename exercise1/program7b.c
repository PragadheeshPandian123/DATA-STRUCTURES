#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

struct Book* createBook(const char* title, const char* author, float price) {
    struct Book* b = (struct Book*)malloc(sizeof(struct Book));
    if (b != NULL) {
        strcpy(b->title, title);
        strcpy(b->author, author);
        b->price = price;
    }
    return b;
}

struct Book* findMostExpensive(struct Book* books[], int n) {
    struct Book* max = books[0];
    for (int i = 1; i < n; i++) {
        if (books[i]->price > max->price) {
            max = books[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);

    struct Book** books=(struct Book **)malloc(sizeof(struct Book)*n);

    for (int i = 0; i < n; i++) {
        char* title,* author;
        title=(char *)malloc(sizeof(char)*100);
        author=(char *)malloc(sizeof(char)*100);

        float price;

        printf("\nEnter details for Book %d\n", i + 1);
        printf("Title : ");
        scanf(" %[^\n]", title);
        printf("Author: ");
        scanf(" %[^\n]", author);
        printf("Price : ");
        scanf("%f", &price);

        books[i] = createBook(title, author, price);
    }

    struct Book* expensive = findMostExpensive(books, n);

    printf("\n--- Most Expensive Book ---\n");
    printf("Title : %s\n", expensive->title);
    printf("Author: %s\n", expensive->author);
    printf("Price : Rs.%.2f\n", expensive->price);

    for (int i = 0; i < n; i++) {
        free(books[i]);
    }

    return 0;
}
