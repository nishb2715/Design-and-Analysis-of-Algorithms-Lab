#write a c program using recursion to convert first n decimal numbers to binary numbers , numbers exist in a file named "numbers.txt".
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MAX_NUMBERS 100
#define MAX_LENGTH 20
void decimalToBinary(int n, char *binary) {
    if (n == 0) {
        strcpy(binary, "0");
        return;
    }
    if (n == 1) {
        strcpy(binary, "1");
        return;
    }
    
    char temp[MAX_LENGTH];
    decimalToBinary(n / 2, temp);
    sprintf(binary, "%s%d", temp, n % 2);
}
void readNumbersFromFile(const char *filename, int *numbers, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    *count = 0;
    while (fscanf(file, "%d", &numbers[*count]) != EOF && *count < MAX_NUMBERS) {
        (*count)++;
    }
    
    fclose(file);
}
void writeBinaryToFile(const char *filename, int *numbers, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    char binary[MAX_LENGTH];
    for (int i = 0; i < count; i++) {
        decimalToBinary(numbers[i], binary);
        fprintf(file, "%d in binary is %s\n", numbers[i], binary);
    }
    fclose(file);
}
int main() {        
    int numbers[MAX_NUMBERS];
    int count = 0;
    
    readNumbersFromFile("numbers.txt", numbers, &count);
    
    writeBinaryToFile("binary_numbers.txt", numbers, count);
    
    printf("Binary conversion completed. Check 'binary_numbers.txt' for results.\n");
    
    return 0;
}
