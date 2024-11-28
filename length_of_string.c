#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], str3[200];
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    strcpy(str3, str1);
    strcat(str3, str2);
    printf("Concatenated string: %s\n", str3);
    printf("Length of concatenated string: %lu\n", strlen(str3));
    return 0;
}
