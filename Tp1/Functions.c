#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void menu()
{
    printf("\n\nUse a letter to select the option.\n\nA-Add the first operating.\nB-Add the second operating.\nC-Calculate all operations.\nD-Show the results.\nE-Exit.\n");
}

float getNum(float num)
{
    printf("\nAdd a number: ");
    scanf("%f", &num);

    return num;
}

float functionSum(float num1, float num2)
{
    float sum;
    sum = num1 + num2;
    return sum;
}

float functionSubtraction(float num1, float num2)
{
    return num1 - num2;
}

float functionDivision(float num1, float num2)
{
     if(num2 == 0)
     {
        return 0;
     }
     else
     {
         return num1 / num2;
     }
}

float functionMultiplication(float num1, float num2)
{
    return num1 * num2;
}

   long int factorial(float num)
{

  long int factorial = 1;
  int i = 0;


    for (i = num; i > 0; i--)
    {
        factorial = factorial * i;
    }

  return factorial;

}
