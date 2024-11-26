#include <stdio.h>

int main() {
    int num;

    // Ask the user to input a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Using if statement to check if the number is positive, negative, or zero
    if (num > 0) {
        printf("%d is positive.\n", num);
    } else if (num < 0) {
        printf("%d is negative.\n", num);
    } else {
        printf("The number is zero.\n");
    }

    return 0;
}
