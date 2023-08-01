#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    int num1, num2;
    while (fscanf(inputFile, "%d %d", &num1, &num2) == 2) {
        int result = gcd(num1, num2);
        printf("The GCD of %d and %d is %d\n", num1, num2, result);
        fprintf(outputFile, "The GCD of %d and %d is %d\n", num1, num2, result);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("GCD values are stored in the output file %s\n", argv[2]);
    return 0;
}
