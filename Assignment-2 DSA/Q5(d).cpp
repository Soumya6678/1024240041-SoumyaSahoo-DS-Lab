#include <stdio.h>

void setUpper(int arr[], int n, int i, int j, int val) {
    if (i <= j) {
        int index = (i-1)*n - (i-2)*(i-1)/2 + (j-i);
        arr[index] = val;
    }
}

int getUpper(int arr[], int n, int i, int j) {
    if (i <= j) {
        int index = (i-1)*n - (i-2)*(i-1)/2 + (j-i);
        return arr[index];
    }
    return 0;
}

void displayUpper(int arr[], int n) {
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            printf("%d ", getUpper(arr, n, i, j));
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    int upper[10] = {0}; // n(n+1)/2 = 10

    setUpper(upper,n,1,1,5); setUpper(upper,n,1,2,8); setUpper(upper,n,1,3,3); setUpper(upper,n,1,4,6);
    setUpper(upper,n,2,2,7); setUpper(upper,n,2,3,2); setUpper(upper,n,2,4,9);
    setUpper(upper,n,3,3,4); setUpper(upper,n,3,4,1);
    setUpper(upper,n,4,4,12);

    printf("Upper Triangular Matrix:\n");
    displayUpper(upper, n);
    return 0;
}
