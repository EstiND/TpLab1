#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"

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

int isFloat(float num)
{
    if(num < 1)
    {
        return 0;
    }
    return 1;
}

int isSector(int num)
{
    printf("%d", num);
    if(num > 10 || num < 1)
    {
        return 0;
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
    flag = isFloat(myEmployee.salary);

    while(flag == 0)
    {
        printf("\nError, el salario ingresado contiene letras.\nIntente de nuevo.\nIngrese el salario del empleado: ");
        fflush(stdin);
        scanf("%f", &myEmployee.salary);
        flag = isFloat(myEmployee.salary);
    }

    printf("Ingrese el sector al que peternece:\n1-Cadeteria.\n2-Mesa de entrada.\n3-Recepcion.\n4-Enfermeria.\n5-Limpieza.");
    printf("\n6-Seguridad.\n7-Administracion.\n8-Recursos humanos.\n9-Tesoreria.\n10-Gerente.\n");
    scanf("%d", &myEmployee.sector);
    flag = isSector(myEmployee.sector);

    while(flag == 0)
    {
        printf("\nError, el sector ingresado no existe, por favor ingrese un sector de la lista.\nIntente de nuevo.\n");
        printf("Ingrese el sector al que peternece:\n1-Cadeteria.\n2-Mesa de entrada.\n3-Recepcion.\n4-Enfermeria.\n5-Limpieza.");
        printf("\n6-Seguridad.\n7-Administracion.\n8-Recursos humanos.\n9-Tesoreria.\n10-Gerente.\n");
        fflush(stdin);
        scanf("%d", &myEmployee.sector);
        flag = isSector(myEmployee.sector);
    }

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
    printf("\n%4d. %12s. %10s.       %.2f.       %2d-", anEmployee.id, anEmployee.name, anEmployee.lastName, anEmployee.salary, anEmployee.sector);
}

void printSector(sEmployee anEmployee)
{
    switch(anEmployee.sector)
    {
    case 1:
        printf("Cadeteria.");
        break;

    case 2:
        printf("Mesa de entrada.");
            break;

        case 3:
            printf("Recepcion.");
            break;

        case 4:
            printf("Enfermeria.");
            break;

        case 5:
            printf("Limpieza.");
            break;

        case 6:
            printf("Seguridad.");
            break;

        case 7:
            printf("Administracion.");
            break;

        case 8:
            printf("Recursos humanos.");
            break;

        case 9:
            printf("Tesoreria.");
            break;

        case 10:
            printf("Gerente.");
            break;
        }
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
                printSector(employeeList[i]);
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

    while(answer < 1 || answer > 1000)
    {
        printf("\nError, el id ingresado es inferior a 1 o mayor a 1000, intente de nuevo.\nIngrese el id del empleado: ");
        scanf("%d", &answer);
    }

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
    int flag;

    i = findEmployeeByID(employeeList, len);

    if(i != -1)
    {
        printf("\n¿Que quieres modificar?\n1-Nombre.\n2-Apellido.\n3-Salario.\n4-Sector.\n5-Volver al menu.\n");
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
            printf("\n1-Cadeteria.\n2-Mesa de entrada.\n3-Recepcion.\n4-Enfermeria.\n5-Limpieza.");
            printf("\n6-Seguridad.\n7-Administracion.\n8-Recursos humanos.\n9-Tesoreria.\n10-Gerente.\n");
            scanf("%d", &sector);
            flag = isSector(sector);
            while(flag == 0)
            {
                printf("\nError, el sector ingresado no existe, por favor ingrese un sector de la lista.\nIntente de nuevo.\n");
                printf("Ingrese el sector al que peternece:\n1-Cadeteria.\n2-Mesa de entrada.\n3-Recepcion.\n4-Enfermeria.\n5-Limpieza.");
                printf("\n6-Seguridad.\n7-Administracion.\n8-Recursos humanos.\n9-Tesoreria.\n10-Gerente.\n");
                fflush(stdin);
                scanf("%d", &sector);
                flag = isSector(sector);
            }
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
        default:
            printf("\nVolviendo al menu.");
            system("pause");
        }
    }
    else
    {
        printf("\nEmpleado no encontrado.\n");
        system("pause");
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
    else
    {
        printf("\nEmpleado no encontrado.\n");
        system("pause");
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
            if(employeeList[i].sector == employeeList[j].sector && employeeList[i].isEmpty != 1 && employeeList[j].isEmpty != 1)

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
                if(employeeList[i].salary > average && employeeList[i].isEmpty != 1)
                {
                    printf("\n%4d. %12s %10s.       %.2f.        %2d.", employeeList[i].id, employeeList[i].name, employeeList[i].lastName, employeeList[i].salary, employeeList[i].sector);
                    printSector(employeeList[i]);

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

