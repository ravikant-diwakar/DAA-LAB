#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int comparisons = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        comparisons++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    FILE *inputFile, *outputFile;
    int option, size, i;
    clock_t start, end;
    double cpu_time_used;

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            inputFile = fopen("inAsce.dat", "r");
            outputFile = fopen("outMergeAsce.dat", "w");
            break;
        case 2:
            inputFile = fopen("inDesc.dat", "r");
            outputFile = fopen("outMergeDesc.dat", "w");
            break;
        case 3:
            inputFile = fopen("inRand.dat", "r");
            outputFile = fopen("outMergeRand.dat", "w");
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid option.\n");
            return 1;
    }

    fscanf(inputFile, "%d", &size);
    int arr[size];
    for (i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }
    fclose(inputFile);

    printf("Before Sorting: ");
    printArray(arr, size);

    start = clock();
    comparisons = 0;
    mergeSort(arr, 0, size - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1e9;

    printf("After Sorting: ");
    printArray(arr, size);

    printf("Number of Comparisons: %lld\n", comparisons);
    printf("Execution Time: %.2f nanoseconds\n", cpu_time_used);

    fprintf(outputFile, "Sorted Array: ");
    for (i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fprintf(outputFile, "\nNumber of Comparisons: %lld\n", comparisons);
    fprintf(outputFile, "Execution Time: %.2f nanoseconds\n", cpu_time_used);

    fclose(outputFile);

    return 0;
}
