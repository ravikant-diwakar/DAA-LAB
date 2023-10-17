#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char *X, char *Y, int m, int n) {
    int T[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                T[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                T[i][j] = 1 + T[i - 1][j - 1];
            else
                T[i][j] = max(T[i - 1][j], T[i][j - 1]);
        }
    }

    int index = T[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (T[i - 1][j] > T[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", T[m][n]);
}

int main() {
    char X[100], Y[100];

    printf("Enter the first string into an array: ");
    scanf("%s", X);

    printf("Enter the second string into an array: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);

    return 0;
}