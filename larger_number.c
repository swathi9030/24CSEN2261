#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        printf("Largest number: %d\n", a);
    else if (b >= a && b >= c)
        printf("Largest number: %d\n", b);
    else
        printf("Largest number: %d\n", c);

    return 0;
}



OUTPUT :
Enter three numbers: 10 25 7
Largest number: 25
