#include <stdio.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of uppercase characters: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of characters must be positive.\n");
        return 1;
    }

    char arr[n];
    printf("Enter %d uppercase characters:\n", n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
        if (arr[i] < 'A' || arr[i] > 'Z') {
            printf("Please enter uppercase characters only.\n");
            return 1;
        }
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }

    return 0;
}
