#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int length;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    length = strlen(str);

    printf("Length of the string: %d\n", length);

    return 0;
}