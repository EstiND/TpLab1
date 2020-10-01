<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"

int printMenu()
{
    int option;

    printf("\n\nBienvenido!, Utiliza numeros para seleccionar la opcion:\n1-Alta empleado.\n2-Modificar empleado.\n3-Remover empleado.\n4-Mostrar empleados.\n5-Salir.\n");
    scanf("%d", &option);

    return option;
}

int isString(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}


void initEmployees(sEmployee employeeList[], int len)
{
    for(int i = 0; i < len; i++)
    {
        employeeList[i].isEmpty = 1;
    }
}

int findSpace(sEmployee employeeList[], int len)
{
    int index = -1;

    for(int i = 0; i < len; i++)
    {
        if(employeeList[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}

sEmployee addEmployee(sEmployee employeeList[], int len)
{
    sEmployee myEmployee;
    int flag;

    printf("Agregue el nombre del empleado: ");
    fflush(stdin);
    scanf("%[^\n]", myEmployee.name);
    flag = isString(myEmployee.name);

    while(flag == 0)
    {
        printf("\nError, el nombre ingresado contiene numeros.\nIntente de nuevo.\nAgregue el nombre del empleado: ");
        fflush(stdin);
        scanf("%[^\n]", myEmployee.name);
        flag = isString(myEmployee.name);
    }

    printf("Agregue el apellido del empleado: ");
    fflush(stdin);
    scanf("%[^\n]", myEmployee.lastName);
    flag = isString(myEmployee.lastName);

    while(flag == 0)
    {
        printf("\nError, el apellido ingresado contiene numeros.\nIntente de nuevo.\nAgregue el apellido del empleado: ");
        fflush(stdin);
        scanf("%[^\n]", myEmployee.lastName);
        flag = isString(myEmployee.lastName);
    }

    printf("Ingrese el salario del empleado: ");
    fflush(stdin);
    scanf("%f", &myEmployee.salary);

    printf("Ingrese el sector: ");
    scanf("%d", &myEmployee.sector);

    printf("\nEmpleado agregado.\n");
    system("pause");

    return myEmployee;
}

int addAllEmployees(sEmployee employeeList[], int len)
{
    int retorno = 0;

    int i;
    i = findSpace(employeeList, len);
    if(i != -1)
    {
        employeeList[i] = addEmployee(employeeList, len);
        employeeList[i].isEmpty = -1;
        employeeList[i].id = i + 1;
        retorno = 1;
    }

    return retorno;
}


void printEmployee(sEmployee anEmployee)
{
    printf("\n%4d. %12s. %10s.       %.2f.        %2d.", anEmployee.id, anEmployee.name, anEmployee.lastName, anEmployee.salary, anEmployee.sector);
}

int printEmployees(sEmployee employeeList[], int len)
{
    int retorno = searchEmployee(employeeList, len);

    if(retorno == 1)
    {
        printf("************************************************************");
        printf("\n   Id       Nombre     Apellido       Salario        Sector");
        for(int i = 0; i < len; i++)
        {
            if(employeeList[i].isEmpty == -1)
            {
                printEmployee(employeeList[i]);
            }
            retorno = 1;
        }
        printf("\n\n");
    }


    return retorno;
}

int findEmployeeByID(sEmployee employeeList[], int len)
{
    int answer;
    int index = -1;

    printf("\nIngrese el id del empleado: ");
    scanf("%d", &answer);

    for(int i = 0; i < len; i++)
    {
        if(employeeList[i].id == answer)
        {
            if(employeeList[i].isEmpty == -1)
            {
                printf("\nEmpleado encontrado.\n");
                index = i;
                break;
            }
        }
    }

    return index;
}

void modifyEmployee(sEmployee employeeList[], int len)
{
    int i;
    int answer;
    char confirm;
    char name[51];
    float salary;
    int sector;

    i = findEmployeeByID(employeeList, len);

    if(i != -1)
    {
        printf("\n¿Que quieres modificar?\n1-Nombre.\n2-Apellido.\n3-Salario.\n4-Sector.\n");
        scanf("%d", &answer);
        switch(answer)
        {
        case 1:
            printf("\nIngrese el nuevo nombre: ");
            scanf("%s", name);
            printf("\n¿Esta seguro que quiere cambiar el nombre? use 's'/'n'\n");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                strcpy(employeeList[i].name, name);
                printf("\nNombre cambiado.\n");
                system("pause");
            }
            else
            {
                printf("\nModificacion cancelada.\n");
                system("pause");
            }
            break;

        case 2:
            printf("\nIngrese el nuevo apellido: ");
            scanf("%s", name);
            printf("\n¿Esta seguro que quiere cambiar el apellido? use 's'/'n'\n");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                strcpy(employeeList[i].lastName, name);
                printf("\nApellido cambiado.\n");
                system("pause");
            }
            else
            {
                printf("\nModificacion cancelada.\n");
                system("pause");
            }
            break;

        case 3:
            printf("\nIngrese el nuevo salario: ");
            scanf("%f", &salary);
            printf("\n¿Esta seguro que quiere cambiar el salario del empleado? use 's'/'n'\n");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                employeeList[i].salary = salary;
                printf("\nSalario cambiado.\n");
                system("pause");
            }
            else
            {
                printf("\nModificacion cancelada.\n");
                system("pause");
            }
            break;

        case 4:
            printf("\nIngrese el nuevo sector: ");
            scanf("%d", &sector);
            printf("\n¿Esta seguro que quiere cambiar el sector del empleado? use 's'/'n'\n");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                employeeList[i].sector = sector;
                printf("\nSector cambiado.\n");
                system("pause");
            }
            else
            {
                printf("\nModificacion cancelada.\n");
                system("pause");
            }
            break;
        }
    }
}

int removeEmployee(sEmployee employeeList[], int len)
{
    char answer;
    int i;
    int retorno = 0;

    i = findEmployeeByID(employeeList, len);

    if(i != -1)
    {
        printf("\n¿Estas seguro que quieres remover un empleado?\n usa 's'/'n'\n");
        fflush(stdin);
        scanf("%c", &answer);
        if(answer == 's')
        {
            employeeList[i].isEmpty = 1;
            retorno = 1;
        }
    }

    return retorno;

}

int searchEmployee(sEmployee employeeList[], int len)
{
    int index = 0;

    for(int i = 0; i < len; i++)
    {
        if(employeeList[i].isEmpty != 1)
        {
            index = 1;
            break;
        }
    }

    return index;
}

int sortEmployees(sEmployee employeeList[], int len)
{
    sEmployee auxEmployee;

    int retorno = 0;

    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(employeeList[i].sector > employeeList[j].sector && employeeList[i].isEmpty != 1 && employeeList[j].isEmpty != 1)
            {
                auxEmployee = employeeList[i];
                employeeList[i] = employeeList[j];
                employeeList[j] = auxEmployee;
                retorno = 1;
            }

        }
    }


    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(employeeList[i].sector == employeeList[j].sector && employeeList[i].isEmpty != 0 && employeeList[j].isEmpty != 0)

            {
                if(strcmp(employeeList[i].lastName, employeeList[j].lastName) > 0)
                {
                    auxEmployee = employeeList[i];
                    employeeList[i] = employeeList[j];
                    employeeList[j] = auxEmployee;
                    retorno = 1;
                }
            }
        }
    }

    return retorno;
}

void showMenu(sEmployee employeeList[], int len)
{
    int answer;
    int counter = 0;
    int flagSort;

    for(int i = 0; i < len; i++)
    {
        if(employeeList[i].isEmpty != 1)
        {
            counter++;

            if(counter >= 2)
            {
                printf("\n1-¿Quiere ordenar la lista de empleados por sector y apellido?\n2-¿Quiere calcular el salario promedio y cuantos empleados lo supera?\n3-Volver al menu.\n");
                scanf("%d", &answer);
                break;
            }
        }
    }

    if(counter <= 1)
    {
        printf("\nNecesitas mas de un empleado para ingresar a este menu.\n");
        system("pause");
        answer = 3;
    }

    switch(answer)
    {
    case 1:
        flagSort = sortEmployees(employeeList, len);
        if(flagSort == 1)
        {
            printf("\nEmpleados ordenados.\n");
            system("pause");
        }
        else
        {

            printf("\nNo se pudo ordenar a los empleados.\n");
            system("pause");
        }
        break;

    case 2:
        calculateSalary(employeeList, len);
        break;
    }
}


void calculateSalary(sEmployee employeeList[], int len)
{
    int counter = 0;
    float sum = 0;
    float average;
    int flag = 0;

    for(int i = 0; i < len; i++)
    {
        if(employeeList[i].isEmpty != 1)
        {
            counter ++;
            sum += employeeList[i].salary;
        }
    }


    if(counter >= 1)
    {
        average = sum / counter;
        system("cls");
        printf("\nEl total de sueldos es: %.2f", sum);
        printf("\nEl salario promedio es: %.2f\n", average);

        for(int i = 0; i < len; i++)
        {
            if(employeeList[i].salary > average && employeeList[i].isEmpty != 1)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
        {
            printf("\nLos empleados que superan el salario promedio son: \n");
            printf("\n  Id       Nombre       Apellido      Salario       Sector");

            for(int i = 0; i < counter; i++)
            {
                if(employeeList[i].salary > average)
                {
                    printf("\n%4d. %12s %10s.       %.2f.        %2d.", employeeList[i].id, employeeList[i].name, employeeList[i].lastName, employeeList[i].salary, employeeList[i].sector);

                }
            }
            printf("\n");
            system("pause");
        }
        else
        {
            printf("\nLa mayoria de los empleados tienen el mismo salario, ninguno supera el salario promedio.\n");
            system("pause");
        }

    }
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int menu()
{
    int option;

    printf("\n\nBienvenido!, Utiliza numeros para seleccionar la opcion:\n1-Alta empleado.\n2-Modificar empleado.\n3-Remover empleado.\n4-Mostrar empleados.\n5-Salir.\n");
    scanf("%d", &option);

    return option;
}

int isString(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}


void initEmployees(sEmployee employeeList[], int len)
{
    for(int i = 0; i < len; i++)
    {
        employeeList[i].isEmpty = 1;
    }
}

int findSpace(sEmployee employeeList[], int len)
{
    int index = -1;

    for(int i = 0; i < len; i++)
    {
        if(employeeList[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}

sEmployee addEmployee(sEmployee employeeList[], int len)
{
    sEmployee myEmployee;
    int flag;

    printf("Agregue el nombre del empleado: ");
    fflush(stdin);
    scanf("%[^\n]", myEmployee.name);
    flag = isString(myEmployee.name);

    while(flag == 0)
    {
        printf("\nError, el nombre ingresado contiene numeros.\nIntente de nuevo.\nAgregue el nombre del empleado: ");
        fflush(stdin);
        scanf("%[^\n]", myEmployee.name);
        flag = isString(myEmployee.name);
    }

    printf("Agregue el apellido del empleado: ");
    fflush(stdin);
    scanf("%[^\n]", myEmployee.lastName);
    flag = isString(myEmployee.lastName);

    while(flag == 0)
    {
        printf("\nError, el apellido ingresado contiene numeros.\nIntente de nuevo.\nAgregue el apellido del empleado: ");
        fflush(stdin);
        scanf("%[^\n]", myEmployee.lastName);
        flag = isString(myEmployee.lastName);
    }

    printf("Ingrese el salario del empleado: ");
    fflush(stdin);
    scanf("%f", &myEmployee.salary);

    printf("Ingrese el sector: ");
    scanf("%d", &myEmployee.sector);

    printf("\nEmpleado agregado.\n");
    system("pause");

    return myEmployee;
}

int addAllEmployees(sEmployee employeeList[], int len)
{
    int retorno = 0;

    int i;
    i = findSpace(employeeList, len);
    if(i != -1)
    {
        employeeList[i] = addEmployee(employeeList, len);
        employeeList[i].isEmpty = -1;
        employeeList[i].id = i + 1;
        retorno = 1;
    }

    return retorno;
}


void printEmployee(sEmployee anEmployee)
{
    printf("\n%4d. %12s. %10s.       %.2f.        %2d.", anEmployee.id, anEmployee.name, anEmployee.lastName, anEmployee.salary, anEmployee.sector);
}

int printEmployees(sEmployee employeeList[], int len)
{
    int retorno = searchEmployee(employeeList, len);

    if(retorno == 1)
    {
        printf("************************************************************");
        printf("\n   Id       Nombre     Apellido       Salario        Sector");
        for(int i = 0; i < len; i++)
        {
            if(employeeList[i].isEmpty == -1)
            {
                printEmployee(employeeList[i]);
            }
            retorno = 1;
        }
        printf("\n\n");
    }


    return retorno;
}

int findEmployeeByID(sEmployee employeeList[], int len)
{
    int answer;
    int index = -1;

    printf("\nIngrese el id del empleado: ");
    scanf("%d", &answer);

    for(int i = 0; i < len; i++)
    {
        if(employeeList[i].id == answer)
        {
            if(employeeList[i].isEmpty == -1)
            {
                printf("\nEmpleado encontrado.\n");
                index = i;
                break;
            }
        }
    }

    return index;
}

void modifyEmployee(sEmployee employeeList[], int len)
{
    int i;
    int answer;
    char confirm;
    char name[51];
    float salary;
    int sector;

    i = findEmployeeByID(employeeList, len);

    if(i != -1)
    {
        printf("\nÂ¿Que quieres modificar?\n1-Nombre.\n2-Apellido.\n3-Salario.\n4-Sector.\n");
        scanf("%d", &answer);
        switch(answer)
        {
        case 1:
            printf("\nIngrese el nuevo nombre: ");
            scanf("%s", name);
            printf("\nÂ¿Esta seguro que quiere cambiar el nombre? use 's'/'n'\n");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                strcpy(employeeList[i].name, name);
                printf("\nNombre cambiado.\n");
                system("pause");
            }
            else
            {
                printf("\nModificacion cancelada.\n");
                system("pause");
            }
            break;

        case 2:
            printf("\nIngrese el nuevo apellido: ");
            scanf("%s", name);
            printf("\nÂ¿Esta seguro que quiere cambiar el apellido? use 's'/'n'\n");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                strcpy(employeeList[i].lastName, name);
                printf("\nApellido cambiado.\n");
                system("pause");
            }
            else
            {
                printf("\nModificacion cancelada.\n");
                system("pause");
            }
            break;

        case 3:
            printf("\nIngrese el nuevo salario: ");
            scanf("%f", &salary);
            printf("\nÂ¿Esta seguro que quiere cambiar el salario del empleado? use 's'/'n'\n");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                employeeList[i].salary = salary;
                printf("\nSalario cambiado.\n");
                system("pause");
            }
            else
            {
                printf("\nModificacion cancelada.\n");
                system("pause");
            }
            break;

        case 4:
            printf("\nIngrese el nuevo sector: ");
            scanf("%d", &sector);
            printf("\nÂ¿Esta seguro que quiere cambiar el sector del empleado? use 's'/'n'\n");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                employeeList[i].sector = sector;
                printf("\nSector cambiado.\n");
                system("pause");
            }
            else
            {
                printf("\nModificacion cancelada.\n");
                system("pause");
            }
            break;
        }
    }
}

int removeEmployee(sEmployee employeeList[], int len)
{
    char answer;
    int i;
    int retorno = 0;

    i = findEmployeeByID(employeeList, len);

    if(i != -1)
    {
        printf("\nÂ¿Estas seguro que quieres remover un empleado?\n usa 's'/'n'\n");
        fflush(stdin);
        scanf("%c", &answer);
        if(answer == 's')
        {
            employeeList[i].isEmpty = 1;
            retorno = 1;
        }
    }

    return retorno;

}

int searchEmployee(sEmployee employeeList[], int len)
{
    int index = 0;

    for(int i = 0; i < len; i++)
    {
        if(employeeList[i].isEmpty != 1)
        {
            index = 1;
            break;
        }
    }

    return index;
}

int sortEmployees(sEmployee employeeList[], int len)
{
    sEmployee auxEmployee;
    int retorno = 0;

    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(employeeList[i].sector < employeeList[j].sector && employeeList[i].isEmpty != 0 && employeeList[j].isEmpty != 0)
            {
                auxEmployee = employeeList[i];
                employeeList[i] = employeeList[j];
                employeeList[j] = auxEmployee;
            }

        }
    }

    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(strcmp(employeeList[i].lastName, employeeList[j].lastName) < 0 && employeeList[i].isEmpty != 0 && employeeList[j].isEmpty != 0)
            {
                auxEmployee = employeeList[i];
                employeeList[i] = employeeList[j];
                employeeList[j] = auxEmployee;
                retorno = 1;
            }

        }
    }

    return retorno;
}

void showMenu(sEmployee employeeList[], int len)
{
    int answer;
    int counter = 0;
    int flagSort;

    for(int i = 0; i < len; i++)
    {
        if(employeeList[i].isEmpty != 1)
        {
            counter++;

            if(counter >= 2)
            {
                printf("\n1-Â¿Quiere ordenar la lista de empleados por sector y apellido?\n2-Â¿Quiere calcular el salario promedio y cuantos empleados lo supera?\n3-Volver al menu.\n");
                scanf("%d", &answer);
                break;
            }
        }
    }

    if(counter <= 1)
    {
        printf("\nNecesitas mas de un empleado para ingresar a este menu.\n");
        system("pause");
        answer = 3;
    }

    switch(answer)
    {
    case 1:
        flagSort = sortEmployees(employeeList, len);
        if(flagSort == 1)
        {
            printf("\nEmpleados ordenados.\n");
            system("pause");
        }
        else
        {

            printf("\nNo se pudo ordenar a los empleados.\n");
            system("pause");
        }
        break;

    case 2:
        calculateSalary(employeeList, len);
        break;
    }
}


void calculateSalary(sEmployee employeeList[], int len)
{
    int counter = 0;
    float sum = 0;
    float average;
    int flag = 0;

    for(int i = 0; i < len; i++)
    {
        if(employeeList[i].isEmpty != 1)
        {
            counter ++;
            sum += employeeList[i].salary;
        }
    }

    if(counter > 1)
    {
        average = sum / counter;
        system("cls");
        printf("\nEl salario promedio es: %.2f\n", average);

        for(int i = 0; i < len; i++)
        {
            if(employeeList[i].salary > average && employeeList[i].isEmpty != 1)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
        {
            printf("\nLos empleados que superan el salario promedio son: \n");
            printf("\n  Id       Nombre       Apellido      Salario       Sector");

            for(int i = 1; i < counter; i++)
            {
                if(employeeList[i].salary > average)
                {
                    printf("\n%4d. %12s %10s.       %.2f.        %2d.", employeeList[i].id, employeeList[i].name, employeeList[i].lastName, employeeList[i].salary, employeeList[i].sector);

                }
            }
            printf("\n");
            system("pause");
        }
        else
        {
            printf("\nLa mayoria de los empleados tienen el mismo salario, ninguno supera el salario promedio.\n");
            system("pause");
        }

    }
}
>>>>>>> 6f9a6fa8eff4b4c2a87df2f14447aba1285317fe
