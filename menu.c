#include <stdio.h>
#include "functions.h"


void menu()
{
    int n = 0;

    printf("\t\t*** Main menu ***\t\t\n\n");
    printf("Please press the corresponding numbers to perform the operations:\n");
    printf("1\tSee current students information\n");
    printf("2\tSearch by filter\n");
    printf("3\tAdd a new student\n");
    printf("4\tModify existing students information\n");
    printf("5\tDelete a student's information\n");
    printf("6\tChange password\n");
    printf("0\tEnd program\n\n");

    scanf("%d",&n);

    switch(n){
        case 1:
            show_all();
            break;
        case 2:
            searchfor();
            break;
        case 3:
            add();
            break;
        case 5:
            del();
            break;
        case 6:
            changepass();
            break;

    }

}
