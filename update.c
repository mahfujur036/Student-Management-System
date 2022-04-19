#include <stdio.h>

void up()
{
    struct update{
        char first_name[15],last_name[15],dept[10];
        int roll;
        float cg;
    } temp[200];
    int roll,c;

    printf("Enter the roll of the student to modify:\t");
    scanf("%d",&roll);

    FILE *f;
    f = fopen("students.txt","r+");
    int i = 0;
    while(!feof(f)){
        fscanf(f,"%d  %s %s  %s  %f",&temp[i].roll,temp[i].first_name,temp[i].last_name,temp[i].dept,&temp[i].cg);
        i++;
    }
    int j = 0;
    while(j<i){
        if(temp[j].roll==roll){
            printf("Name:\t%s %s\nRoll:\t%d\nDepartment:\t%s\nCGPA:\t%.2f\n\n",temp[j].first_name,temp[j].last_name,temp[j].roll,temp[j].dept);
            printf("What do you want to modify:\n1\tName\n2\tRoll\n3\tDepartment\n4\tCGPA\n\n");
            scanf("%d",&c);
            //switch(c){
            //    case 1:
            }
        }
    }


