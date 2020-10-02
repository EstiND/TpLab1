#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"

void menu(sEmployee employeeList[], int len)
{
    int answer;
    int flag;
    int flagAdd;
    int flagModify;
    int flagRemove;
    int flagPrint;

    do
    {
        system("cls");
        answer = printMenu();

        switch(answer)
        {
        case 1:
            flagAdd = addAllEmployees(employeeList, len);
            if(flagAdd == 0)
            {
                printf("\nNo hay mas lugar en el sistema.\n");
                system("pause");
            }
            break;

        case 2:
            flag = searchEmployee(employeeList, len);
            if(flag == 1)
            {
                printEmployees(employeeList, len);
                modifyEmployee(employeeList, len);
            }
            else
            {
                printf("\nSin datos para modificar.\n");
                system("pause");
            }
            break;

        case 3:
            flag = searchEmployee(employeeList, len);
            if(flag == 1)
            {
                printEmployees(employeeList, len);
                flagRemove = removeEmployee(employeeList, len);
                if(flagRemove == 1)
                {
                    printf("\nEmpleado removido.\n");
                    system("pause");
                }
                else
                {
                    printf("\nOperacion cancelada.\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nNo hay empleados para remover.\n");
                system("pause");
            }
            break;

        case 4:
            flag = searchEmployee(employeeList, len);
            if(flag == 1)
            {
                flagPrint = printEmployees(employeeList, len);
                if(flagPrint == 1)
                {
                    system("pause");
                    showMenu(employeeList, len);
                }
            }
            else
            {
                printf("\nNo hay empleados que mostrar.\n");
                system("pause");
            }
            break;

        case 5:
            printf("Hasta luego.\n");
            break;

        default:
            printf("\nUse numeros para acceder al programa.\n");
            system("pause");
            fflush(stdin);
        }
    }
    while(answer != 5);
}

int printMenu()
{
    int option;

    printf("\n\nBienvenido!, Utiliza numeros para seleccionar la opcion:\n1-Alta empleado.\n2-Modificar empleado.\n3-Remover empleado.\n4-Mostrar empleados.\n5-Salir.\n");
    scanf("%d", &option);

    return option;
}
