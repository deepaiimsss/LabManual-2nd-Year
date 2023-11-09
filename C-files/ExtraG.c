//Write a program that will convert the given decimal input in to other number systems Hexadecimal, Octal, and Binary. The class Conversion will have the methods as GetNumber, Print Number, Convert To Hexadecimal, Convert To Octal, Convert To Binary.



#include <stdio.h>

class Conversion {
private:
    int decimalNumber;

public:
    void GetNumber() {
        printf("Enter a decimal number: ");
        scanf("%d", &decimalNumber);
    }

    void PrintNumber() {
        printf("Decimal Number: %d\n", decimalNumber);
    }

    void ConvertToHexadecimal() {
        printf("Hexadecimal: %X\n", decimalNumber);
    }

    void ConvertToOctal() {
        printf("Octal: %o\n", decimalNumber);
    }

    void ConvertToBinary() {
        printf("Binary: ");
        int binary[32];
        int index = 0;
        int temp = decimalNumber;

        // Convert decimal to binary
        while (temp > 0) {
            binary[index] = temp % 2;
            temp /= 2;
            index++;
        }

        // Print binary representation
        for (int i = index - 1; i >= 0; --i) {
            printf("%d", binary[i]);
        }

        printf("\n");
    }
};

int main() {
    Conversion conversion;

    // Get decimal number from the user
    conversion.GetNumber();

    // Print the decimal number
    conversion.PrintNumber();

    // Convert and print in hexadecimal, octal, and binary
    conversion.ConvertToHexadecimal();
    conversion.ConvertToOctal();
    conversion.ConvertToBinary();

    return 0;
}
