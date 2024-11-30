#include <stdio.h>

int main() {
    char choice;
    float temp, converted_temp;

    printf("Enter 'C' for Celsius to Fahrenheit or 'F' for Fahrenheit to Celsius: ");
    scanf(" %c", &choice);

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    if (choice == 'C' || choice == 'c') {
        converted_temp = (temp * 9.0 / 5.0) + 32.0;
        printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temp, converted_temp);
    } else if (choice == 'F' || choice == 'f') {
        converted_temp = (temp - 32.0) * 5.0 / 9.0;
        printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temp, converted_temp);
    } else {
        printf("Invalid input. Please enter 'C' or 'F'.\n");
    }

    return 0;
}
