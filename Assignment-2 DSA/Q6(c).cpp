#include <stdio.h>

void multiply(int a[20][3], int b[20][3], int c[40][3]) {
    if (a[0][1] != b[0][0]) {
        printf("Matrix dimensions not compatible for multiplication!\n");
        return;
    }

    int i, j, k, l, m = 1;
    c[0][0] = a[0][0];
    c[0][1] = b[0][1];
    c[0][2] = 0;

    for (i = 0; i < a[0][0]; i++) {
        for (j = 0; j < b[0][1]; j++) {
            int sum = 0;
            for (k = 1; k <= a[0][2]; k++) {
                if (a[k][0] == i) {
                    for (l = 1; l <= b[0][2]; l++) {
                        if (b[l][0] == a[k][1] && b[l][1] == j) {
                            sum += a[k][2] * b[l][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                c[m][0] = i;
                c[m][1] = j;
                c[m][2] = sum;
                m++;
            }
        }
    }
    c[0][2] = m - 1;
}

void display(int a[40][3]) {
    int i, n = a[0][2];
    for (i = 0; i <= n; i++)
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
}

int main() {
    int a[20][3] = {
        {2, 3, 3}, {0, 0, 1}, {0, 2, 2}, {1, 1, 3}
    };
    int b[20][3] = {
        {3, 2, 3}, {0, 1, 4}, {1, 0, 5}, {2, 1, 6}
    };
    int c[40][3];

    printf("Matrix A (Triplet):\n");
    display(a);
    printf("\nMatrix B (Triplet):\n");
    display(b);

    multiply(a, b, c);

    printf("\nMultiplication Result (Triplet):\n");
    display(c);

    return 0;
}
