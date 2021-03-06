#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief Muestra un menu de opciones principal donde se llama a las funciones en base a la respuesta.
 *
 * \param str[] char Recibe un dato de tipo char.
 * \return int Devuelve 1 si es cadena, y 0 si no lo es.
 * \return void.
 *
 */
void menu(sEmployee employeeList[], int len);

/** \brief Muestra un parrafo donde se pide por una respuesta.
 *
 * \return int Retorna el numero recibido indicando la opcion.
 *
 */
int printMenu();

#endif // MENU_H_INCLUDED
