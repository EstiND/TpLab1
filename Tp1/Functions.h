#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

 /** \brief Una funcion void con el unico proposito de mostrar un menu con 5 opciones.
  *
  * \return No retorna nada por ser un void.
  *
  */

void menu();

 /** \brief Una funcion que recibe numeros para las operaciones.
  *
  * \param Solicita un numero.
  *
  * \return Retorna el numero recibido.
  */

float getNum(float num);

 /** \brief Suma los dos numeros ingresados.
  *
  * \param num1 contiene el primer numero solicitado por float num.
  * \param num2 contiene el segundo numero solicitado por float num.
  *
  * \return float retorna la suma de num1 y num2.
  */

float functionSum(float num1, float num2);

 /** \brief Resta los dos numeros ingresados.
  *
  * \param num1 contiene el primer numero solicitado por float num.
  * \param num2 contiene el segundo numero solicitado por float num.
  *
  * \return float retorna la resta de num1 y num2.
  */

float functionSubtraction(float num1, float num2);

 /** \brief Divide los dos numeros ingresados.
  *
  * \param num1 contiene el primer numero solicitado por float num
  * \param num2 contiene el segundo numero solicitado por float num
  * \return float retorna la divison de num1 y num2
  *
  */

float functionDivision(float num1, float num2);

 /** \brief Multiplica los dos numeros ingresados
  *
  * \param num1 contiene el primer numero solicitado por float num
  * \param num2 contiene el segundo numero solicitado por float num
  * \return float retorna la multiplicacion de num1 y num2
  *
  */

float functionMultiplication(float num1, float num2);

 /** \brief Calcula el factorial de un numero
  *
  * \param num1 y num2 contiene el primer numero solicitado por float num
  *
  * \return float retorna el factorial de num1 y luego el dnum2
  *
  */

long int factorial(float num);

#endif // FUNCTIONS_H_INCLUDED
