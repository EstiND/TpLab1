#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    char option;
    float num1;
    float num2;
    float sum;
    float subtraction;
    float division;
    float multiplication;
    long int factorial1;
    long int factorial2;
    int flagNum1 = 0;
    int flagNum2 = 0;
    int flagOpetarions = 0;

    do{
    system("cls");
    menu();
    scanf("%c",&option);

    switch (option){

    case 'a':
    num1 = getNum(num1);
    flagNum1 = 1;
    printf("The first operating has been added.\n\n");
    system("pause");
    break;

    case 'b':
    num2 = getNum(num2);
    flagNum2 = 1;
    printf("The second operating has been added.\n\n");
    system("pause");
    break;

    case 'c':
    if (flagNum1 == 0){
    printf("\nYou have to add the first operating before this option.\n\n");
    system("pause");
    }
    else if (flagNum2 == 0){
    printf("\nYou have to add the second operating before this option.\n\n");
    system("pause");
    }
    else
    {
    sum = functionSum(num1, num2);
    subtraction = functionSubtraction(num1, num2);
    division = functionDivision(num1, num2);
    multiplication = functionMultiplication(num1, num2);
    factorial1 = factorial(num1);
    factorial2 = factorial(num2);
    flagOpetarions = 1;
    printf("Calculating....\n\n");
    system("pause");
    }
    break;

    case 'd':

    if (flagOpetarions == 0)
    {
    printf("You need to do the operations before show them\n");
    system("pause");
    }
    else
    {
    printf("\nThe sum of %.2f + %.2f is: %.2f\n", num1, num2, sum);
    printf("\nThe subtraction of %.2f - %.2f is: %.2f\n", num1, num2, subtraction);

    if(num2 == 0)
    {
    printf("\nYou can't divide for 0.\n");
    }
    else
    {
    printf("\nThe division of %.2f / %.2f is: %.2f\n", num1, num2, division);
    }

    printf("\nThe multiplication of %.2f * %.2f is: %.2f\n\n", num1, num2, multiplication);

    if(num1 < 0)
    {
    printf("\nIs not possible to calculate the factorial of the negative number.\n");
    }
    else
    {
    printf("\nthe factorial of %.2f is %ld\n", num1, factorial1);
    }
    if(num2 < 0){
    printf("\nIs not possible to calculate the factorial of the negative number.\n\n");
    }
    else
    {
    printf("\nThe factorial of %.2f is %ld\n", num2, factorial2);
    }

    system("pause");
    }
    break;

    case 'e':
    printf("\nGood bye\n\n");
    break;
}

   } while (option != 'e');

    return 0;
}

