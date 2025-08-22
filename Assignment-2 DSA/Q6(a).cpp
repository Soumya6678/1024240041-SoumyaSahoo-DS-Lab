#include <stdio.h>

void transpose(int a[20][3], int b[20][3]) {
    int i, j, k;
    int rows = a[0][0], cols = a[0][1], n = a[0][2];

    b[0][0] = cols;
    b[0][1] = rows;
    b[0][2] = n;

    k = 1;
    for (i = 0; i < cols; i++) {
        for (j = 1; j <= n; j++) {
            if (a[j][1] == i) {
                b[k][0] = a[j][1];
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }
        }
    }
}

void display(int a[20][3]) {
    int i, n = a[0][2];
    for (i = 0; i <= n; i++)
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
}

int main() {
    int a[20][3] = {
        {4, 5, 4}, {0, 1, 5}, {1, 3, 8}, {2, 0, 3}, {3, 2, 6}
    };
    int b[20][3];

    printf("Original Sparse Matrix (Triplet Form):\n");
    display(a);

    transpose(a, b);

    printf("\nTranspose Sparse Matrix (Triplet Form):\n");
    display(b);

    return 0;
}
