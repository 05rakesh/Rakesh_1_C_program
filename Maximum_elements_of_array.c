#include <stdio.h>
int main() {
    int arr[] = {3, 5, 9, 1, 6};
    int max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    printf("Maximum element: %d\n", max);
    return 0;
}
