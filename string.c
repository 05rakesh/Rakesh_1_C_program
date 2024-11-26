include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, isPalindrome = 1;

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Check for palindrome using a loop
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            isPalindrome = 0; // Not a palindrome
            break;
        }
    }

    // Output the result
    if (isPalindrome) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
