#include "fuctions.h"

float ingresoDeNumeros(float num)
{
    printf("Ingrese un numero: ");
    scanf("%f",&num);

    return num;

}

float suma(float numUno, float numDos)
{
   return numUno + numDos;
}

float resta(float numUno, float numDos)
{
   return numUno - numDos;
}

float division(float numUno, float numDos)
{
    float resultado;

    if(numUno == 0 || numDos == 0)
    {
        printf("No es posible dividir por cero\n");
    }
    else
    {
        resultado = numUno / numDos;
    }

    return resultado;
}

float multiplicacion(float numUno, float numDos)
{
    return numUno * numDos;
}

long int factorial(float num)
{

  long int factorial = 1;
  int i = 0;

    if(num<0)
    {
        factorial = printf("No se posible calcular el factorial de un numero negativo.");
    }

    for (i = num; i > 0; i--)
    {
        factorial = factorial * i;
    }

  return factorial;

}
