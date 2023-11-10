//Write a program that will convert the given decimal input in to other number systems Hexadecimal, Octal, and Binary. The class Conversion will have the methods as GetNumber, Print Number, Convert To Hexadecimal, Convert To Octal, Convert To Binary.


#include <stdio.h>

typedef struct {
    int decimalNumber;
} Conversion;

void GetNumber(Conversion *conversion);
void PrintNumber(Conversion conversion);
void ConvertToHexadecimal(Conversion conversion);
void ConvertToOctal(Conversion conversion);
void ConvertToBinary(Conversion conversion);

int main() {
    Conversion conversion;

    GetNumber(&conversion);

    PrintNumber(conversion);

    ConvertToHexadecimal(conversion);
    ConvertToOctal(conversion);
    ConvertToBinary(conversion);

    return 0;
}

void GetNumber(Conversion *conversion) {
    printf("Enter a decimal number: ");
    scanf("%d", &(conversion->decimalNumber));
}

void PrintNumber(Conversion conversion) {
    printf("Decimal Number: %d\n", conversion.decimalNumber);
}

void ConvertToHexadecimal(Conversion conversion) {
    printf("Hexadecimal: %X\n", conversion.decimalNumber);
}

void ConvertToOctal(Conversion conversion) {
    printf("Octal: %o\n", conversion.decimalNumber);
}

void ConvertToBinary(Conversion conversion) {
    printf("Binary: ");
    int binary[32];
    int index = 0;
    int temp = conversion.decimalNumber;

    while (temp > 0) {
        binary[index] = temp % 2;
        temp /= 2;
        index++;
    }

    for (int i = index - 1; i >= 0; --i) {
        printf("%d", binary[i]);
    }

    printf("\n");
}
