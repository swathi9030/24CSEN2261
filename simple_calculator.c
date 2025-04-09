#include <stdio.h>

int main() {
    char operator;
    double num1, num2;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator) {
        case '+': printf("Result = %.2f\n", num1 + num2); break;
        case '-': printf("Result = %.2f\n", num1 - num2); break;
        case '*': printf("Result = %.2f\n", num1 * num2); break;
        case '/': 
            if (num2 != 0)
                printf("Result = %.2f\n", num1 / num2);
            else
                printf("Error! Division by zero.\n");
            break;
        default: printf("Invalid operator.\n");
    }

    return 0;
}



OUTPUT :
Enter an operator (+, -, *, /): +
Enter two numbers: 10 5
Result: 15.00
