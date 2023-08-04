#include <stdio.h>

int main() {
    FILE *file;
    int n;

    file = fopen("number.txt", "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    int numbers[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &numbers[i]);
    }

    fclose(file);

    printf("The content of the array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    int duplicates = 0;
    int mostRepeatingElement = numbers[0];
    int maxCount = 1;

    for (int i = 0; i < n; i++) {
        if (numbers[i] == 0) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (numbers[j] == numbers[i]) {
                count++;
                numbers[j] = 0;
            }
        }

        if (count > 1) {
            duplicates++;
        }

        if (count > maxCount) {
            maxCount = count;
            mostRepeatingElement = numbers[i];
        }
    }

    printf("Total number of duplicate values = %d\n", duplicates);
    printf("The most repeating element in the array = %d\n", mostRepeatingElement);

    return 0;
}
