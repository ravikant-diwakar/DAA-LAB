#include <stdio.h>
#include <stdlib.h>

void decToBinary(int decimalNum, FILE* outFile) {
    if (decimalNum > 0) {
        decToBinary(decimalNum / 2, outFile);
        fprintf(outFile, "%d", decimalNum % 2);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char* sourceFileName = argv[2];
    char* destFileName = argv[3];

    FILE* inFile = fopen(sourceFileName, "r");
    FILE* outFile = fopen(destFileName, "w");

    if (!inFile) {
        printf("Error opening source file: %s\n", sourceFileName);
        return 1;
    }

    if (!outFile) {
        printf("Error opening destination file: %s\n", destFileName);
        return 1;
    }

    int decimalNum;
    for (int i = 0; i < n; i++) {
        if (fscanf(inFile, "%d", &decimalNum) == 1) {
            fprintf(outFile, "The binary equivalent of %d is ", decimalNum);
            decToBinary(decimalNum, outFile);
            fprintf(outFile, "\n");

            printf("The binary equivalent of %d is ", decimalNum);
            decToBinary(decimalNum, stdout);
            printf("\n");
        } else {
            printf("Reached end of file before reading %d decimal numbers.\n", n);
            break;
        }
    }

    fclose(inFile);
    fclose(outFile);
    printf("Conversion completed successfully.\n");
    return 0;
}
