#include <stdio.h>

void setDiagonal(int arr[], int n, int i, int j, int val) {
    if (i == j)
        arr[i-1] = val;
}

int getDiagonal(int arr[], int n, int i, int j) {
    if (i == j) return arr[i-1];
    return 0;
}

void displayDiagonal(int arr[], int n) {
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            printf("%d ", getDiagonal(arr, n, i, j));
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    int diag[4] = {0};

    setDiagonal(diag, n, 1,1,5);
    setDiagonal(diag, n, 2,2,8);
    setDiagonal(diag, n, 3,3,9);
    setDiagonal(diag, n, 4,4,12);

    printf("Diagonal Matrix:\n");
    displayDiagonal(diag, n);
    return 0;
}

