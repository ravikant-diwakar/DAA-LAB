#include <stdio.h>

void findSecondSmallestAndLargest(int arr[], int n) {
    int firstSmallest, secondSmallest;
    int firstLargest, secondLargest;

    // Initialize the variables
    if (arr[0] < arr[1]) {
        firstSmallest = arr[0];
        secondSmallest = arr[1];
    } else {
        firstSmallest = arr[1];
        secondSmallest = arr[0];
    }

    firstLargest = secondLargest = arr[0] > arr[1] ? arr[0] : arr[1];

    // Traverse the array
    for (int i = 2; i < n; i++) {
        if (arr[i] < firstSmallest) {
            secondSmallest = firstSmallest;
            firstSmallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != firstSmallest) {
            secondSmallest = arr[i];
        }

        if (arr[i] > firstLargest) {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != firstLargest) {
            secondLargest = arr[i];
        }
    }

    printf("Second Smallest: %d\n", secondSmallest);
    printf("Second Largest: %d\n", secondLargest);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    findSecondSmallestAndLargest(arr, n);

    return 0;
}
