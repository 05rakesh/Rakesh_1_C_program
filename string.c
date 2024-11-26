include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, isPalindrome = 1;

    
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            isPalindrome = 0; 
            break;
        }
    }

    
    if (isPalindrome) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
