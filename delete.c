#include <stdio.h>

void del()
{
    FILE *f1, *f2;
    char ch;
    int del, temp = 1, roll;

    struct update{
        char first_name[15],last_name[15],dept[10];
        int roll;
        float cg;
    } stru[100];

    f1 = fopen("students.txt", "r");
    ch = getc(f1);
    printf("Enter the roll number to delete:\t");
    scanf("%d",&roll);

    int i = 1;
    while(!feof(f1)){
        fscanf(f1,"%d  %s %s  %s  %f",&stru[i].roll,stru[i].first_name,stru[i].last_name,stru[i].dept,&stru[i].cg);
        if(stru[i].roll==roll)
            break;
        i++;
    }
    rewind(f1);
    printf("%d\t",i);
    printf("%d\t",stru[i].roll);
    printf("%d\t",roll);


    f2 = fopen("new.txt", "w");
    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(f1);

        if (temp != i)
        {
            putc(ch, f2);
        }
        if (ch == '\n')
        {
            temp++;
        }
    }
    fclose(f1);
    fclose(f2);
    remove("students.txt");

    rename("new.txt", "students.txt");
    printf("\n The contents of file after being modified are as follows:\n");
    f1 = fopen("sorted.txt", "r");
    ch = getc(f1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(f1);
    }
    fclose(f1);
}
