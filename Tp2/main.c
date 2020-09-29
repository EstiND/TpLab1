#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    sEmployee employeeList[TAM];
    initEmployees(employeeList, TAM);
    int answer;
    int flag;
    int flagAdd;
    int flagModify;
    int flagRemove;
    int flagPrint;


    do
    {
        system("cls");
        answer = menu();

        switch(answer)
        {
        case 1:
            flagAdd = addAllEmployees(employeeList, TAM);
            if(flagAdd == 0)
            {
                printf("\nNo hay mas lugar en el sistema.\n");
                system("pause");
            }
            break;

        case 2:
            flag = searchEmployee(employeeList, TAM);
            if(flag == 1)
            {
                printEmployees(employeeList, TAM);
                modifyEmployee(employeeList, TAM);
            }
            else
            {
                printf("\nSin datos para modificar.\n");
                system("pause");
            }
            break;

        case 3:
            flag = searchEmployee(employeeList, TAM);
            if(flag == 1)
            {
                printEmployees(employeeList, TAM);
                flagRemove = removeEmployee(employeeList, TAM);
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
            flag = searchEmployee(employeeList, TAM);
            if(flag == 1)
            {
                flagPrint = printEmployees(employeeList, TAM);
                if(flagPrint == 1)
                {
                    system("pause");
                    showMenu(employeeList, TAM);
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
            printf("\nError, por favor use numeros para seleecionar la opcion.\n");
            system("pause");
            break;
        }
    }
    while(answer != 5);

    return 0;
}
