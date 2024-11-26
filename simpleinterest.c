#include <stdio.h>

int main() {
    float principal, rate, time, simpleInterest;

    // Input: Principal, Rate, and Time
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &rate);
    printf("Enter the time period (in years): ");
    scanf("%f", &time);

    // Calculate Simple Interest
    simpleInterest = (principal * rate * time) / 100;

    // Output the result
    printf("Simple Interest = %.2f\n", simpleInterest);

    return 0;
}
