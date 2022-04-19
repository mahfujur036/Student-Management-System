#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int total_students = 0;

int main()
{
    FILE *f;
    char user[20], pass[20], password[20], c;
    int i;
    printf("\t\t*** WELCOME TO STUDENT MANAGEMENT SYSTEM ***\n\n");
    printf("Enter your login details to continue\n");

    f = fopen("pass.txt","r");
    fscanf(f,"%s",password);
    fclose(f);

    while(1){
        printf("Username: \t");
        gets(user);
        printf("Password: \t");
        i = 0;
        while((c=getch())!=13)
        {
            pass[i] = c;
            printf("*");
            i++;
        }
        pass[i] = '\0';
        system("cls");
        if(strcmp(user,"admin")==0 && strcmp(pass,password)==0)
        {
            menu();
            break;
        }
        else{
            printf("invalid username or password\n\n");
        }
    }
    return 0;
}

void changepass()
{
    FILE *f;
    char ch, newpass[20], oldpass[20];

    system("cls");
    //printf("Are you sure you want to change the password? (Y/N)\n");
    //scanf("%c",&ch);
    //if(ch=='Y' || ch=='y'){
        printf("Enter new password:\t");
        scanf("%s",newpass);
        f = fopen("pass.txt","w");
        fprintf(f,"%s",newpass);
        fclose(f);
        printf("\nPassword changed successfully");
    //}

    printf("\nPress any key to get back to main menu\n");
    getch();
    system("cls");
    menu();

}
