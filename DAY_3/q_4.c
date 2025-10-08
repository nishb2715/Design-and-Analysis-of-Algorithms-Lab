//write a c program using recursive function for liner search in an array of integers
#include <stdio.h>
#include <stdlib.h>
int linearSearch(int arr[], int size, int target, int index) {
    if (index >= size) {
        return -1; //  for the case when target is not found
    }
    if (arr[index] == target) {
        return index; // for the case when target is found
    }
    return linearSearch(arr, size, target, index + 1); // for searching in the next index
}
int main() {
    int n, target;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element to search: ");
    scanf("%d", &target);
    
    int result = linearSearch(arr, n, target, 0);
    
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array: %d\n", target);
    }
    
    free(arr); // for freeing up the allocated memory
    return 0;
}
