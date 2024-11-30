#include <stdio.h>

int main() {
    double value, result;
    char unit_from[10], unit_to[10];

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit_to);

    if (strcmp(unit_from, "meter") == 0 && strcmp(unit_to, "kilometer") == 0) {
        result = value / 1000;
        printf("%.2lf meters is equal to %.2lf kilometers\n", value, result);
    } else if (strcmp(unit_from, "kilometer") == 0 && strcmp(unit_to, "meter") == 0) {
        result = value * 1000;
        printf("%.2lf kilometers is equal to %.2lf meters\n", value, result);
    } else if (strcmp(unit_from, "gram") == 0 && strcmp(unit_to, "kilogram") == 0) {
        result = value / 1000;
        printf("%.2lf grams is equal to %.2lf kilograms\n", value, result);
    } else if (strcmp(unit_from, "kilogram") == 0 && strcmp(unit_to, "gram") == 0) {
        result = value * 1000;
        printf("%.2lf kilograms is equal to %.2lf grams\n", value, result);
    } else {
        printf("Invalid units!\n");
    }

    return 0;
}