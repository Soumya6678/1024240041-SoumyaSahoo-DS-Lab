#include <stdio.h>

void add(int a[20][3], int b[20][3], int c[40][3]) {
    int i = 1, j = 1, k = 1;
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf("Matrix dimensions not same, cannot add!\n");
        return;
    }
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        } else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        } else {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
    }
    while (i <= a[0][2]) {
        c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2]; i++; k++;
    }
    while (j <= b[0][2]) {
        c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2]; j++; k++;
    }
    c[0][2] = k - 1;
}

void display(int a[40][3]) {
    int i, n = a[0][2];
    for (i = 0; i <= n; i++)
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
}

int main() {
    int a[20][3] = {
        {3, 3, 3}, {0, 0, 3}, {1, 1, 5}, {2, 2, 7}
    };
    int b[20][3] = {
        {3, 3, 3}, {0, 0, 2}, {1, 1, 4}, {2, 0, 6}
    };
    int c[40][3];

    printf("Matrix A (Triplet):\n");
    display(a);
    printf("\nMatrix B (Triplet):\n");
    display(b);

    add(a, b, c);

    printf("\nAddition Result (Triplet):\n");
    display(c);

    return 0;
}
