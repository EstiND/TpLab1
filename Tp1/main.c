#include <stdio.h>
#include <stdlib.h>
#include "fuctions.h"

int main()
{
    int answer;
    float operating1;
    float operating2;
    float sumResult;
    float subtractionResult;
    float divisionResult;
    float multiplicationResult;
    float factorialResult;

    do {

    system("cls");
    printf("\n\nWelcome!, use a number to select your option:\n1-Add the first operating.\n2-Add the second operating.\n3-Calculate all the operations.\n4-Show results.\n5-Exit.\n");
    scanf("%d", &answer);

    switch (answer)
    {
    case 1:
    printf("Add the first operating: ");
    scanf("%f", &operating1);
    printf("got cha'\n");
    system("pause");
    break;

    case 2:
    printf("Add the second operating: ");
    scanf("%f", &operating2);
    printf("got cha'\n");
    system("pause");
    break;

    case 3:
    sumResult = operating1 + operating2;
    subtractionResult = operating1 - operating2;
    divisionResult = operating1 / operating2;
    multiplicationResult = operating1 * operating2;
    //Factorial asi re lindo

    printf("\nCalculating.");
    printf("\nCalculating..");
    printf("\nCalculating...");
    printf("\nCalculating....");
    printf("\nCalculating.....");

    break;

    case 4:
    printf("The results are :\n-Sum :%.0f\n-Subtraction :%.0f\n-Division :%.2f\n-Multiplication :%.2f\n-Factiorial :\n", sumResult, subtractionResult, divisionResult, multiplicationResult);
    system("pause");
    break;
    }

    } while (answer != 5);

    return 0;
}

