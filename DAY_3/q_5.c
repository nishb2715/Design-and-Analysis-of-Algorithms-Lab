// find the gcd of two numbers using recursion 
#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a; // base case
    }
    return gcd(b, a % b); // recursive case
}
int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    if (a < 0 || b < 0) {
        printf("Please enter non-negative integers.\n");
        return 1;
    }
    
    int result = gcd(a, b);
    printf("The GCD of %d and %d is: %d\n", a, b, result);
    
    return 0;
}
