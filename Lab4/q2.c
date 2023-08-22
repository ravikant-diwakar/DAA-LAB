#include <stdio.h>
#include <stdlib.h>

int comparisons = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            comparisons++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    comparisons++;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void readAndSort(char *inputFileName, char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    int size;
    fscanf(inputFile, "%d", &size);
    int arr[size];
    
    for (int i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }
    fclose(inputFile);

    comparisons = 0;
    quickSort(arr, 0, size - 1);

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fclose(outputFile);

    printf("After Sorting: ");
    displayArray(arr, size);
    printf("Number of Comparisons: %d\n", comparisons);
    if (comparisons == size - 1) {
        printf("Scenario: Best-case\n");
    } else if (comparisons == (size * (size - 1)) / 2) {
        printf("Scenario: Worst-case\n");
    } else {
        printf("Scenario: Neither best-case nor worst-case\n");
    }
}

int main() {
    int choice;
    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");

    printf("Enter option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            readAndSort("inAsce.dat", "outQuickAsce.dat");
            break;
        case 2:
            readAndSort("inDesc.dat", "outQuickDesc.dat");
            break;
        case 3:
            readAndSort("inRand.dat", "outQuickRand.dat");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option\n");
    }

    return 0;
}
