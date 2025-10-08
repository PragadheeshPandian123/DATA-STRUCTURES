#include <stdio.h>

int main() {
    int units;
    printf("Enter electricity units consumed: ");
    scanf("%d", &units);

    if (units <= 100)
        printf("Bill: Rs. %d\n", units * 2);
    else if (units <= 200)
        printf("Bill: Rs. %d\n", 100 * 2 + (units - 100) * 3);
    else if (units <= 300)
        printf("Bill: Rs. %d\n", 100 * 2 + 100 * 3 + (units - 200) * 4);
    else
        printf("Bill: Rs. %d\n", 100 * 2 + 100 * 3 + 100 * 4 + (units - 300) * 5);

    return 0;
}
