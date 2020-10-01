<<<<<<< HEAD
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;

/** \brief Muestra un menu de opciones principal donde se llama a las funciones en base a la respuesta.
 *
 * \param str[] char Recibe un dato de tipo char.
 * \return int Devuelve 1 si es cadena, y 0 si no lo es.
 * \return void.
 *
 */
void menu(sEmployee employeeList[], int len);

/** \brief Muestra un menu de opciones.
 *
 * \return int retorna la opcion elegida en el menu.
 *
 */
int printMmenu();


/** \brief Comprueba si el dato recibido es una cadena de caracteres.
 *
 * \param str[] char Recibe un dato de tipo char.
 * \return int Devuelve 1 si es cadena, y 0 si no lo es.
 *
 */
int isString(char str[]);


/** \brief Inicializa el isEmpty de la lista de empleados para cargar datos.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return void.
 *
 */
void initEmployees(sEmployee employeeList[], int len);


/** \brief Busca en todo el array isEmpty en busca de un lugar vacio.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return int Retorna la posicion del lugar.
 *
 */
int findSpace(sEmployee employeeList[], int len);

/** \brief Solicita datos del empleado.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return sEmployee Retorna una estrucutra auxiliar donde se almacenaron los datos.
 *
 */
sEmployee addEmployee(sEmployee employeeList[], int len);

/** \brief Agrega a un empleado usando otra funcion.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return int Retorna 1 si cargo al empleado, y 0 si no hay lugar.
 *
 */
int addAllEmployees(sEmployee employeeList[], int len);

/** \brief Muestra los empleados cargados.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \return void.
 *
 */
void printEmployee(sEmployee anEmployee);

/** \brief Comprueba si hay por lo menos un empleado, y luego los muestra.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return int Retorna 1 si fue capaz de encontrar al menos a un empleado.
 *
 */
int printEmployees(sEmployee employeeList[], int len);

/** \brief Busca a un empleado usando el id.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return int Si encuentra al empleado retorna su indice, sino retorna -1.
 *
 */
int findEmployeeByID(sEmployee employeeList[], int len);

/** \brief Modifica a un dato de un empleado.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return void.
 *
 */
void modifyEmployee(sEmployee employeeList[], int len);

/** \brief Realiza una baja logica.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return int Retona 1 si el empleado fue removido y 0 si fue cancelado.
 *
 */
int removeEmployee(sEmployee employeeList[], int len);

/** \brief Busca al menos un empleado.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return int Retorna 1 si encontro un empleado, y 0 si no encontro.
 *
 */
int searchEmployee(sEmployee employeeList[], int len);

/** \brief Ordena a los empleados por sector de menor a mayor, y luego por apellido, de la A a la Z.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return int Retorna 1 si fue capaz de orndenarlos.
 *
 */
int sortEmployees(sEmployee employeeList[], int len);

/** \brief Muestra un menu adentro de la funcion mostrar empleados.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return void.
 *
 */
void showMenu(sEmployee employeeList[], int len);

/** \brief Calcula el salario promedio usando y quienes los supera.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe el tamaño del array.
 * \return void
 *
 */
void calculateSalary(sEmployee employeeList[], int len);


#endif // ARRAYEMPLOYEES_H_INCLUDED
=======
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;


/** \brief Muestra un menu de opciones.
 *
 * \return int retorna la opcion elegida en el menu.
 *
 */
int menu();


/** \brief Comprueba si el dato recibido es una cadena de caracteres.
 *
 * \param str[] char Recibe un dato de tipo char.
 * \return int Devuelve 1 si es cadena, y 0 si no lo es.
 *
 */
int isString(char str[]);


/** \brief Inicializa el isEmpty de la lista de empleados para cargar datos.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return void.
 *
 */
void initEmployees(sEmployee employeeList[], int len);


/** \brief Busca en todo el array isEmpty en busca de un lugar vacio.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return int Retorna la posicion del lugar.
 *
 */
int findSpace(sEmployee employeeList[], int len);

/** \brief Solicita datos del empleado.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return sEmployee Retorna una estrucutra auxiliar donde se almacenaron los datos.
 *
 */
sEmployee addEmployee(sEmployee employeeList[], int len);

/** \brief Agrega a un empleado usando otra funcion.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return int Retorna 1 si cargo al empleado, y 0 si no hay lugar.
 *
 */
int addAllEmployees(sEmployee employeeList[], int len);

/** \brief Muestra los empleados cargados.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \return void.
 *
 */
void printEmployee(sEmployee anEmployee);

/** \brief Comprueba si hay por lo menos un empleado, y luego los muestra.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return int Retorna 1 si fue capaz de encontrar al menos a un empleado.
 *
 */
int printEmployees(sEmployee employeeList[], int len);

/** \brief Busca a un empleado usando el id.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return int Si encuentra al empleado retorna su indice, sino retorna -1.
 *
 */
int findEmployeeByID(sEmployee employeeList[], int len);

/** \brief Modifica a un dato de un empleado.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return void.
 *
 */
void modifyEmployee(sEmployee employeeList[], int len);

/** \brief Realiza una baja logica.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return int Retona 1 si el empleado fue removido y 0 si fue cancelado.
 *
 */
int removeEmployee(sEmployee employeeList[], int len);

/** \brief Busca al menos un empleado.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return int Retorna 1 si encontro un empleado, y 0 si no encontro.
 *
 */
int searchEmployee(sEmployee employeeList[], int len);

/** \brief Ordena a los empleados por sector de menor a mayor, y luego por apellido, de la A a la Z.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return int Retorna 1 si fue capaz de orndenarlos.
 *
 */
int sortEmployees(sEmployee employeeList[], int len);

/** \brief Muestra un menu adentro de la funcion mostrar empleados.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return void.
 *
 */
void showMenu(sEmployee employeeList[], int len);

/** \brief Calcula el salario promedio usando y quienes los supera.
 *
 * \param employeeList[] sEmployee Recibe la estructura y la lista de empleados.
 * \param len int Recibe la cantidad de veces que va a iterar.
 * \return void
 *
 */
void calculateSalary(sEmployee employeeList[], int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
>>>>>>> 6f9a6fa8eff4b4c2a87df2f14447aba1285317fe
