#include <stdio.h>
#include <string.h>
int main() {
    char str[] = "Hello";
    int n = strlen(str);
    printf("Reversed string: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
