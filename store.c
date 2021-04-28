#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

struct login{
    char fname[100];
    char lname[100];
    char username[20];
    char password[20];
};
int registe()
{
    FILE *log;
    log = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\user.txt", "w");
    struct login l;
    printf("Enter First name :"); scanf("%s", l.fname);
    printf("Enter Last name :"); scanf("%s", l.lname);
    printf("Enter Username name :"); scanf("%s", l.username);
    printf("Enter Password name :"); scanf("%s", l.password);
    fwrite(&l, sizeof(l), 1, log);
    fclose(log);
    printf("\n\nyour User name is UserID\n");
    printf("Now login with UserID and Password\n");
    printf("\nPress any key to continue.....");
    system("pause");
    system("CLS");
}
int login()
{
    char username[20], password[20];
    FILE *log;
    log = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\user.txt", "r");
    struct login l;
    printf("UserID: ");
    scanf("%s", &username);
    printf("\nPassword: ");
    scanf("%s", &password);
    while (fread(&l, sizeof(l), 1, log))
    {
        if(strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)
        {
            printf("Sucessful login\n");
        } else {
            printf("Please enter correct UserID and Password\n");
        }
    }
    fclose(log);
}
int main()
{
    int choice;
    printf("Press '1' for Login \nPress '2' for Register\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        system("CLS");
        login();
    } else if(choice == 2)
    {
        system("CLS");
        registe();
        
    }
}