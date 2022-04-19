#include <stdio.h>

//Show all students info
void show_all()
{
    sorting();
    int total = 0;
    char first_name[15],last_name[15],dept[20];
    int roll,i;
    float cg;

    FILE *f;
    system("cls");
    f = fopen("sorted.txt","r");
    printf("Roll\tName\t\t\tDept.\tCGPA\n");
    while(!feof(f)){
        fscanf(f,"%d%s%s%s%f",&roll,first_name,last_name,dept,&cg);
        if(strlen(first_name)>11 || strlen(last_name)>11)
            printf("%d\t%s %s\t%s\t%.2f\n",roll,first_name,last_name,dept,cg);
        else
            printf("%d\t%s %s\t\t%s\t%.2f\n",roll,first_name,last_name,dept,cg);

        total++;
    }
    fclose(f);
    printf("\nCurrent total students: %d\n",total);
    printf("\n0\tBack to main menu\n\tAny key to exit\n");
    scanf("%d",&i);
    if(i==0){
        system("cls");
        menu();
    }
}
