#include <stdio.h>

void setTriDiagonal(int arr[], int n, int i, int j, int val) {
    if (i-j == 0) arr[n-1 + i-1] = val;       
    else if (i-j == 1) arr[i-2] = val;        
    else if (j-i == 1) arr[2*n-1 + i-1] = val; 
}

int getTriDiagonal(int arr[], int n, int i, int j) {
    if (i-j == 0) return arr[n-1 + i-1];
    else if (i-j == 1) return arr[i-2];
    else if (j-i == 1) return arr[2*n-1 + i-1];
    else return 0;
}

void displayTriDiagonal(int arr[], int n) {
    int i, j;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            printf("%d ", getTriDiagonal(arr, n, i, j));
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    int tri[3*4-2]; // 3n-2 = 10
    for (int k=0; k<3*n-2; k++) tri[k]=0;

    setTriDiagonal(tri,n,1,1,1);
    setTriDiagonal(tri,n,2,1,2);
    setTriDiagonal(tri,n,2,2,3);
    setTriDiagonal(tri,n,1,2,4);
    setTriDiagonal(tri,n,3,3,5);
    setTriDiagonal(tri,n,3,2,6);
    setTriDiagonal(tri,n,2,3,7);

    printf("Tri-Diagonal Matrix:\n");
    displayTriDiagonal(tri, n);
    return 0;
}
