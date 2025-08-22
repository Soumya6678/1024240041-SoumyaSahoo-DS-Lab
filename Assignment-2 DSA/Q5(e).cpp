#include <stdio.h>

void setSymmetric(int arr[], int n, int i, int j, int val) {
    if (i >= j) {
        int index = i*(i-1)/2 + (j-1);
        arr[index] = val;
    }
    else {
        int index = j*(j-1)/2 + (i-1);
        arr[index] = val;
    }
}

int getSymmetric(int arr[], int n, int i, int j) {
    if (i >= j) {
        int index = i*(i-1)/2 + (j-1);
        return arr[index];
    } else {
        int index = j*(j-1)/2 + (i-1);
        return arr[index];
    }
}

void displaySymmetric(int arr[], int n) {
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            printf("%d ", getSymmetric(arr, n, i, j));
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    int sym[10] = {0}; // n(n+1)/2 = 10

    setSymmetric(sym,n,1,1,1);
    setSymmetric(sym,n,2,1,2); setSymmetric(sym,n,2,2,3);
    setSymmetric(sym,n,3,1,4); setSymmetric(sym,n,3,2,5); setSymmetric(sym,n,3,3,6);
    setSymmetric(sym,n,4,1,7); setSymmetric(sym,n,4,2,8); setSymmetric(sym,n,4,3,9); setSymmetric(sym,n,4,4,10);

    printf("Symmetric Matrix:\n");
    displaySymmetric(sym, n);
    return 0;
}
