#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define L 1000

int main()
{
    sEmployee employeeList[L];
    initEmployees(employeeList, L);

    menu(employeeList, L);

    return 0;
}
