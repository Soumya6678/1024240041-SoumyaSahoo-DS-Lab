#include <stdio.h>

void setLower(int arr[], int n, int i, int j, int val) {
    if (i >= j) {
        int index = i*(i-1)/2 + (j-1);
        arr[index] = val;
    }
}

int getLower(int arr[], int n, int i, int j) {
    if (i >= j) {
        int index = i*(i-1)/2 + (j-1);
        return arr[index];
    }
    return 0;
}

void displayLower(int arr[], int n) {
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            printf("%d ", getLower(arr, n, i, j));
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    int lower[10] = {0}; // n(n+1)/2 = 10

    setLower(lower,n,1,1,5);
    setLower(lower,n,2,1,3); setLower(lower,n,2,2,8);
    setLower(lower,n,3,1,6); setLower(lower,n,3,2,7); setLower(lower,n,3,3,9);
    setLower(lower,n,4,1,2); setLower(lower,n,4,2,4); setLower(lower,n,4,3,1); setLower(lower,n,4,4,12);

    printf("Lower Triangular Matrix:\n");
    displayLower(lower, n);
    return 0;
}
