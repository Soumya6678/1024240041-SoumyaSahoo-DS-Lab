#include <stdio.h>

int main() {
    int m, n;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);

    int a[m][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int found = 0;

    for (int i = 0; i < m; i++) {
        
        int rowMin = a[i][0];
        int colIndex = 0;
        for (int j = 1; j < n; j++) {
            if (a[i][j] < rowMin) {
                rowMin = a[i][j];
                colIndex = j;
            }
        }

        
        int k;
        for (k = 0; k < m; k++) {
            if (a[k][colIndex] > rowMin) {
                break; 
            }
        }

        
        if (k == m) {
            printf("Saddle point found: %d at position (%d,%d)\n", rowMin, i, colIndex);
            found = 1;
        }
    }

    if (!found) {
        printf("No saddle point found in the matrix.\n");
    }

    return 0;
}
