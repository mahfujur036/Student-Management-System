#include <stdio.h>
#include <string.h>
#include "functions.h"

void add()
{
    FILE *f;
    f = fopen("students.txt","a");
    int i = 0, v;
    while(v)
    {
        //fprintf(f,"\n");
        system("cls");
        printf("Please enter the details of the student:\n");
        printf("Full name:\t");
        getchar();
        gets(st[i].name);
        printf("Roll:\t");
        scanf("%d",&st[i].roll);
        printf("Department:\t");
        scanf("%s",st[i].dept);
        printf("CGPA:\t");
        scanf("%f",&st[i].cgpa);
        fprintf(f,"%d  %s  %s  %.2f\n",st[i].roll,st[i].name,st[i].dept,st[i].cgpa);

        printf("\n1\tAdd another student\n0\tReturn to main menu\n");
        scanf("%d",&v);
        i++;
    }
    system("cls");
    fclose(f);
    menu();

}


void bubblesort(int x[],int n)
{
    int temp,j,i,s = 1;
    for(i = 0; i<n-1 && s==1; i++)
    {
        s=0;
        for (j=0; j<n-i-1; j++)
            if (x[j]>x[j+1])
            {
                s=1;
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
    }
}

void sorting()
{
    int roll[100],x[100],n,i,j;
    float cg[100];
    char first_name[100][30], last_name[100][30], dept[100][10];
    FILE *f1,*f2;

    f1 = fopen("students.txt","r");
    f2 = fopen("sorted.txt","w");
    i = 0;

    while(!feof(f1)){
        fscanf(f1,"%d  %s %s  %s  %f\n",&roll[i],first_name[i],last_name[i],dept[i],&cg[i]);
        x[i]= roll[i];
        i++;
    }

    n = i;

    bubblesort(x,n);

    for(i=0; i<n; i++){
        for (j=0; j<n; j++){
            if(x[i]==roll[j]){
                fprintf(f2,"%d  %s %s  %s  %.2f\n",roll[j],first_name[j],last_name[j],dept[j],cg[j]);
            }
        }
    }
    fclose(f1);
    fclose(f2);

}
