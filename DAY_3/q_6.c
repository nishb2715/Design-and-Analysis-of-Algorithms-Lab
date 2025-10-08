// write a c program using recursive function for fibonacci series , find the best case and worst case time complexity for 5th term, count and print how many times the recursive function is called and make it order of n

#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n, int *count) {
    (*count)++;
    if (n <= 1) {
        return n; // base case
    }
    return fibonacci(n - 1, count) + fibonacci(n - 2, count); // recursive case
}
int main() {
    int n, count = 0;
    printf("Enter the term number for Fibonacci series: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }
    
    int result = fibonacci(n, &count);
    printf("The %dth term in the Fibonacci series is: %d\n", n, result);
    printf("The recursive function was called %d times.\n", count);
    
    // Best case time complexity: O(1) when n = 0 or n = 1
    // Worst case time complexity: O(2^n) for larger n due to exponential growth
    // The function is called approximately n/2 times in the worst case.
    
    return 0;
}


