#include <stdio.h>
#include <string.h>

int main() {
    int num1, num2;
    char op[3]; 
    
    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    printf("Enter operator (+, -, *, /, %%, ==, !=, >, <, >=, <=, &&, ||, !, &, |, ^, ~, <<, >>): ");
    scanf("%s", op);


    if (strcmp(op, "==") == 0)
        printf("%d == %d = %s", num1, num2, (num1 == num2) ? "true" : "false");
    else if (strcmp(op, "!=") == 0)
        printf("%d != %d = %s", num1, num2, (num1 != num2) ? "true" : "false");
    else if (strcmp(op, ">") == 0)
        printf("%d > %d = %s", num1, num2, (num1 > num2) ? "true" : "false");
    else if (strcmp(op, "<") == 0)
        printf("%d < %d = %s", num1, num2, (num1 < num2) ? "true" : "false");
    else if (strcmp(op, ">=") == 0)
        printf("%d >= %d = %s", num1, num2, (num1 >= num2) ? "true" : "false");
    else if (strcmp(op, "<=") == 0)
        printf("%d <= %d = %s", num1, num2, (num1 <= num2) ? "true" : "false");
    else if (strcmp(op, "&&") == 0)
        printf("%d && %d = %s", num1, num2, (num1 && num2) ? "true" : "false");
    else if (strcmp(op, "||") == 0)
        printf("%d || %d = %s", num1, num2, (num1 || num2) ? "true" : "false");
    else if (strcmp(op, "<<") == 0)
        printf("%d << %d = %d", num1, num2, num1 << num2);
    else if (strcmp(op, ">>") == 0)
        printf("%d >> %d = %d", num1, num2, num1 >> num2);
    else {
        
        switch (op[0]) {
            case '+':
                printf("%d + %d = %d", num1, num2, num1 + num2);
                break;
            case '-':
                printf("%d - %d = %d", num1, num2, num1 - num2);
                break;
            case '*':
                printf("%d * %d = %d", num1, num2, num1 * num2);
                break;
            case '/':
                if (num2 == 0)
                    printf("Zero Division Error");
                else
                    printf("%d / %d = %d", num1, num2, num1 / num2);
                break;
            case '%':
                if (num2 == 0)
                    printf("Modulo by zero error");
                else
                    printf("%d %% %d = %d", num1, num2, num1 % num2);
                break;
            case '&':
                printf("%d & %d = %d", num1, num2, num1 & num2);
                break;
            case '|':
                printf("%d | %d = %d", num1, num2, num1 | num2);
                break;
            case '^':
                printf("%d ^ %d = %d", num1, num2, num1 ^ num2);
                break;
            case '~':
                printf("~%d = %d", num1, ~num1);  
                break;
            case '!':
                printf("!%d = %s", num1, (!num1) ? "true" : "false");
                break;
            default:
                printf("Invalid operator");
        }
    }

    return 0;
}
