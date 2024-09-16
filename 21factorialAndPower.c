#include <stdio.h>

int factorial(int n) {
    if (n < 0) {
        printf("Factorial of a negative number is undefined.\n");
        return -1;  // return an error code for invalid input
    }
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int power(int base, int exp) {
    if (exp < 0) {
        printf("Negative exponents are not supported.\n");
        return -1;  // return an error code for invalid input
    }
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

int main() {
    int n = 5;
    int fact = factorial(n);
    if (fact != -1)  // check for error code
        printf("Factorial of %d is %d\n", n, fact);

    int base = 2, exp = 5;
    int result = power(base, exp);
    if (result != -1)  // check for error code
        printf("%d^%d is %d\n", base, exp, result);

    return 0;
}
