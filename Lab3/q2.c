#include <stdio.h>

void insertionSort(int arr[], int size, int *comparisons) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*comparisons)++;
        }

        arr[j + 1] = key;
    }
}

void printArrayToFile(int arr[], int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void displayFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        printf("%d ", num);
    }

    fclose(file);
}

int main() {
    int choice;
    do {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            const char *inputFileNames[] = {"inAsce.dat", "inDesc.dat", "inRand.dat"};
            const char *outputFileNames[] = {"outInsAsce.dat", "outInsDesc.dat", "outInsRand.dat"};

            int arr[500]; // Max array size
            int size;

            FILE *inputFile = fopen(inputFileNames[choice - 1], "r");
            if (inputFile == NULL) {
                printf("Error opening input file.\n");
                return 1;
            }

            size = 0;
            while (fscanf(inputFile, "%d", &arr[size]) != EOF) {
                size++;
            }

            fclose(inputFile);

            int comparisons = 0;
            insertionSort(arr, size, &comparisons);

            printf("Before Sorting: ");
            displayFileContents(inputFileNames[choice - 1]);
            printf("\nAfter Sorting: ");
            printArrayToFile(arr, size, outputFileNames[choice - 1]);
            displayFileContents(outputFileNames[choice - 1]);
            printf("\nNumber of Comparisons: %d\n", comparisons);

            int n = size;
            int bestCaseComparisons = n - 1;
            int worstCaseComparisons = (n * (n - 1)) / 2;

            if (comparisons == bestCaseComparisons) {
                printf("Scenario: Best-case\n");
            } else if (comparisons == worstCaseComparisons) {
                printf("Scenario: Worst-case\n");
            } else {
                printf("Scenario: Neither best nor worst case\n");
            }
        } else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid option. Please select again.\n");
        }
    } while (1);

    return 0;
}
