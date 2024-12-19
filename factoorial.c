#include <stdio.h>
int factorial(int n) {
    printf("Entering factorial(%d)\n", n);
    if (n == 0 || n == 1) {
        printf("Returning 1 from factorial(%d)\n", n);
        return 1; 
    } else {
        int result = n * factorial(n - 1); 
        printf("Returning %d from factorial(%d)\n", result, n);
        return result;
    }
}
int main() {
    int number;
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int result = factorial(number);
        printf("Factorial of %d is %d\n", number, result);
    }
    return 0;
}
