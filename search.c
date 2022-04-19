#include <stdio.h>

void searchfor()
{
    system("cls");
    char first_name[15],last_name[15],dept[10],strquery[15],deptquery[10];
    int roll,query,res = 0,v,i;
    float cg;

    FILE *f;
    f = fopen("students.txt","r");
    printf("Search by:\n1\tRoll\n2\tFirst or last name\n3\tDepartment\n");
    scanf("%d",&v);
    system("cls");

    switch(v){
        case 1: printf("Enter the roll to search for:\t");
                scanf("%d",&query);
                break;
        case 2: printf("Enter the first or last name:\t");
                scanf("%s",strquery);
                break;
        case 3: printf("Enter the short code for department (UPPERCASE):\t");
                scanf("%s",deptquery);
                break;
        default:printf("Invalid input\n");
                system("cls");
                menu();
    }

    system("cls");
    printf("Roll\tName\t\t\tDept.\tCGPA\n");
    while(!feof(f)){
        fscanf(f,"%d  %s  %s  %s  %f",&roll,first_name,last_name,dept,&cg);
        if(roll==query || strcmp(strquery,first_name)==0 || strcmp(strquery,last_name)==0 || strcmp(deptquery,dept)==0){
            res = 1;
            if(strlen(first_name)>11 || strlen(last_name)>11)
                printf("%d\t%s %s\t%s\t%.2f\n",roll,first_name,last_name,dept,cg);
            else
                printf("%d\t%s %s\t\t%s\t%.2f\n",roll,first_name,last_name,dept,cg);
        }
    }

    if(res==0)
        printf("\nNo search results found\n");

    fclose(f);

    printf("\n0\tBack to main menu\n");
    scanf("%d",&i);

    if(i==0){
        system("cls");
        menu();
    }
}
