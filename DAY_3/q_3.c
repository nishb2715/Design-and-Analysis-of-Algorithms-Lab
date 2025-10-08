//write a c program using recursive function for binary search in an array of integers
#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // Target not found
    }
    
    int mid = left + (right - left) / 2; // To avoid overflow
    
    if (arr[mid] == target) {
        return mid; // Target found
    } else if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target); // Search in the left half
    } else {
        return binarySearch(arr, mid + 1, right, target); // Search in the right half
    }
}
int main() {
    int n, target;
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer for the number of elements.\n");
        return 1;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the target element to search: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, 0, n - 1, target);
    
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array: %d\n", target);
    }
    
    free(arr); // Freeing up the allocated memory
    return 0;
}
