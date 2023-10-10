#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void findLCS(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    int lcsLength[m + 1][n + 1];

    // Compute LCS length using dynamic programming
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                lcsLength[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                lcsLength[i][j] = 1 + lcsLength[i - 1][j - 1];
            else
                lcsLength[i][j] = max(lcsLength[i - 1][j], lcsLength[i][j - 1]);
        }
    }

    // Find LCS characters from the length matrix
    int index = lcsLength[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        } else if (lcsLength[i - 1][j] > lcsLength[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", lcsLength[m][n]);
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string into an array: ");
    scanf("%s", str1);

    printf("Enter the second string into an array: ");
    scanf("%s", str2);

    findLCS(str1, str2);

    return 0;
}
