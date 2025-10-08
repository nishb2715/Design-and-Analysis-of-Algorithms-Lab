# write a c program using recursion to calculate sum of numbers from 1 to N
#include <stdio.h>
#include <stdlib.h>
int sumRecursion(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sumRecursion(n - 1);
}
int main() {
    int n;
    printf("Enter a positive integer N: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }
    
    int sum = sumRecursion(n);
    printf("The sum of numbers from 1 to %d is: %d\n", n, sum);
    
    return 0;
}
