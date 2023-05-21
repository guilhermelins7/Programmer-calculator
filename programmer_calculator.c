#include <stdio.h>
#include <math.h>
#include <windows.h> // Library for Terminal Commands in Windows

void cleanTerminal() // just to make it more visually clear
{
    system("Pause");
    system("cls");
}

int numberInsert()
{
    fflush(stdin); // Clean Buffer

    int number;

    printf("Enter the number for convert:\n");
    scanf("%d", &number);

    return number;
}

int numericSystemCheck()
{
    fflush(stdin); // Clean Buffer

    int numericSystem;

    do
    {
        printf("What is the Numeric System of the number?\n");
        printf("1 - Decimal\n2 - Binary\n3 - Octal\n4 - Hexadecimal\n");
        scanf("%d", &numericSystem);

    } while ((numericSystem < 1 || numericSystem > 4) && printf("Invalid number. Please enter a number between 1 and 4.\n"));

    return numericSystem;
}

void displayNumber(int number, int System)
{
    char numericSystem[12];

    switch (System) // assign a string.
    {
    case 1:
        strcpy(numericSystem, "Decimal");
        break;
    case 2:
        strcpy(numericSystem, "Binary");
        break;
    case 3:
        strcpy(numericSystem, "Octal");
        break;
    case 4:
        strcpy(numericSystem, "Hexadecimal");
        break;
    }

    printf("%s number entered: %d\n\n", numericSystem, number);
}

void binaryToDecimal(int binary)
{
    int decimal = 0, decimalPotency = 0, decimalPlaces;

    for (decimalPlaces = 1; decimalPlaces < binary; decimalPlaces *= 10)
    {
        decimalPotency++;
    }

    while (decimalPotency >= 0)
    {
        decimal += pow(2, decimalPotency) * (binary / decimalPlaces);
        decimalPotency--;
        binary %= decimalPlaces;
        decimalPlaces /= 10;
    }

    printf("Decimal: %d", decimal);
}

void decimalToBinary(int decimal)
{
    int binary = 0, binaryPlace = 1;

    while (decimal > 0)
    {
        binary += (decimal % 2) * binaryPlace;
        decimal /= 2;
        binaryPlace *= 10;
    }

    printf("Binary: %d\n", binary);
}

void decimalToOctal(int number)
{
    int octal = 0;

    for (int octalPlace = 1; number > 0; octalPlace *= 10)
    {
        octal += ((number % 8) * octalPlace);
        number /= 8;
    }

    printf("Octal: %d\n", octal);
}

int main()
{
    int number, numericSystem;

    number = numberInsert();
    numericSystem = numericSystemCheck();

    cleanTerminal();

    displayNumber(number, numericSystem);

    if (numericSystem == 1)
    {
        decimalToBinary(number);
        decimalToOctal(number);
    }
    else if (numericSystem == 2)
    {
        binaryToDecimal(number);
    }

    return 0;
}
