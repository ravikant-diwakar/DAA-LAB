#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    for (int i = 0; i < p2; i++) {
        EXCHANGE(p1 + i, p1 + p2 - 1);
    }
}

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int A[N];
    printf("Enter an array of size %d: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int p2;
    printf("Enter the number of elements to be rotated: ");
    scanf("%d", &p2);

    printf("Before ROTATE:");
    for (int i = 0; i < N; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");

    ROTATE_RIGHT(A, p2);

    printf("After ROTATE:");
    for (int i = 0; i < N; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");

    return 0;
}
