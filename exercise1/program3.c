#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    float x, term, sum = 0;
    int sign = 1;

    printf("Enter the value of x in degrees: ");
    scanf("%f", &x);

    printf("Enter number of terms (n): ");
    scanf("%d", &n);

    x = x * (3.14159 / 180);

    for(i = 1; i <= 2*n-1; i += 2) {
        float fact = 1;
        for(int j = 1; j <= i; j++) {
            fact *= j;
        }

        term = pow(x, i) / fact;
        sum += sign * term;
        sign *= -1; 
    }

    printf("The sine of the angle is: %.6f\n", sum);

	printf("Multiplication table using while loop : \n");
	int step,num;
	printf("Enter the number and steps : ");
	scanf("%d %d",&num,&step);
	for(int k=1;k<=step;k++)
	{
		printf("%d * %d = %d\n",num,k,num*k);
	}
	int a = 5, b;
    printf("Pattern using DO...WHILE loop:\n");
    do {
        b = 1;
        do {
            printf("* ");
            b++;
        } while(b <= a);
        printf("\n");
        a--;
    } while(a >= 1);
    return 0;
}
