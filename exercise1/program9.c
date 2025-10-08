#include <stdio.h>
#include <stdlib.h>

#define SALE_EVENT 

#ifdef SALE_EVENT
    #define DISCOUNT_RATE 0.15
    #define APPLY_DISCOUNT(amount) ((amount) - ((amount) * DISCOUNT_RATE))
#else
    #define APPLY_DISCOUNT(amount) (amount)
#endif

enum Category {
    ELECTRONICS = 1,
    CLOTHING,
    GROCERIES
};

float getGST(enum Category cat) {
    switch (cat) {
        case ELECTRONICS: return 0.18;
        case CLOTHING:    return 0.12;
        case GROCERIES:   return 0.05;
        default:          return 0.0;
    }
}

const char* getCategoryName(enum Category cat) {
    switch (cat) {
        case ELECTRONICS: return "Electronics (18% GST)";
        case CLOTHING:    return "Clothing (12% GST)";
        case GROCERIES:   return "Groceries (5% GST)";
        default:          return "Unknown";
    }
}

int main() {
    enum Category choice;
    float basePrice, gst, discounted, total;

    do {
        printf("\n----- Menu Based E-Commerce Billing -----\n");
        printf("1. Electronics\n");
        printf("2. Clothing\n");
        printf("3. Groceries\n");
        printf("4. Exit\n");
        printf("Enter a category (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program. Thank you!\n");
            exit(0);
        }

        if (choice >= ELECTRONICS && choice <= GROCERIES) {
            printf("\nCategory Selected: %s\n", getCategoryName(choice));
            printf("Enter product price: Rs.");
            scanf("%f", &basePrice);

            discounted = APPLY_DISCOUNT(basePrice);
            gst = discounted * getGST(choice);
            total = discounted + gst;

            printf("\n--- Invoice ---\n");
            printf("Product Price      : Rs.%.2f\n", basePrice);

#ifdef SALE_EVENT
            printf("Sale Discount (15%%): -Rs.%.2f\n", basePrice - discounted);
#endif

            printf("GST (%.0f%%)          : Rs.%.2f\n", getGST(choice) * 100, gst);
            printf("Total Payable       : Rs.%.2f\n", total);
        } else {
            printf("Invalid choice. Try again.\n");
        }

    } while (1);

    return 0;
}
