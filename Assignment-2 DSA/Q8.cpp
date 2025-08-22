#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        int isDistinct = 1;  
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = 0;  
                break;
            }
        }
        if (isDistinct) {
            distinctCount++;
        }
    }

    printf("Total number of distinct elements: %d\n", distinctCount);

    return 0;
}
