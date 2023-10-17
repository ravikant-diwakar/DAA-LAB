#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

int m[MAX_SIZE][MAX_SIZE];
int s[MAX_SIZE][MAX_SIZE];

int matrix_chain_multiplication(int p[], int n) {
  for (int i = 1; i <= n; i++) {
    m[i][i] = 0;
  }

  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      int min = INT_MAX;
      for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < min) {
          min = q;
          s[i][j] = k;
        }
      }
      m[i][j] = min;
    }
  }

  return m[1][n];
}

void print_optimal_parenthesization(int s[][MAX_SIZE], int i, int j) {
  if (i == j) {
    printf("A%d", i);
  } else {
    printf("(");
    print_optimal_parenthesization(s, i, s[i][j]);
    printf(" ");
    print_optimal_parenthesization(s, s[i][j] + 1, j);
    printf(")");
  }
}

int main() {
  int n;
  printf("Enter number of matrices: ");
  scanf("%d", &n);

  int p[n + 1];
  for (int i = 1; i <= n; i++) {
    printf("Enter row and col size of A%d: ", i);
    scanf("%d %d", &p[i - 1], &p[i]);
  }

  int min_scalar_multiplications = matrix_chain_multiplication(p, n);

  printf("M Table:\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }

  printf("S Table:\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", s[i][j]);
    }
    printf("\n");
  }

  printf("Optimal parenthesization: ");
  print_optimal_parenthesization(s, 1, n);
  printf("\n");

  printf("The optimal ordering of the given matrices requires %d scalar multiplications\n", min_scalar_multiplications);

  return 0;
}
