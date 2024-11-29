#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

int main() {
    int n, i;
    float total_salary = 0;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", employees[i].name);
        printf("Enter ID: ");
        scanf("%d", &employees[i].id);
        printf("Enter salary: ");
        scanf("%f", &employees[i].salary);
        total_salary += employees[i].salary;
    }

    float average_salary = total_salary / n;
    printf("\nAverage salary of all employees: %.2f\n", average_salary);

    return 0;
}
