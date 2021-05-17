#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
FILE *log;
FILE *new_rec;
FILE *id;
char firstname[100], lastname[100];
int count_eiei = 0;

char* d_name[50];
int d_price[50];
int d_amount[50];
int balance, all_price = 0, price_buy;
int mainmenu(int uid);
int transcation(int uid);
int shopping(int uid);
int charge_cal(int uid);
void bill(int uid);

struct login{
    char fname[100];
    char lname[100];
    char username[20];
    char password[20];
    float balance;
};
void load_start(){ /* Loading Start Screen */
    int i;
    for(i=0; i<=100; i++){
        system("CLS");
        printf("                               [ %d%% / 100%% ]", i);
        Sleep(20);
    }
    Sleep(500);
    system("CLS");
    printf("                               [ Done! ]");
    Sleep(500);
    system("CLS");
}
void load(){ /* Loading Start Screen */
    int i;
    for(i=0; i<=100; i++){
        system("CLS");
        printf("                               [ %d%% / 100%% ]", i);
        Sleep(20);
    }
    Sleep(500);
    system("CLS");
    printf("                               [ Deposited successfully! ]");
    Sleep(500);
    system("CLS");
}
int transcation(uid)
{
    char username[20], password[20], lusername[20], lpassword[20], lfirstname[100], llastname[100];
    int luid, choice;
    float lbalance, deposit, withdrawn;
    log = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\user.txt", "r");
    new_rec = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\new_user.txt", "a");
    system("COLOR B");
    printf("    _________________________________________________________\n"
           "          ____              _    _                  \n"
           "         |  _ \\            | |  (_)                \n"
           "         | |_) | __ _ _ __ | | ___ _ __   __ _      \n"
           "         |  _ < / _` | '_ \\| |/ / | '_ \\ / _` |   \n"
           "         | |_) | (_| | | | |   <| | | | | (_| |     \n"
           "         |____/ \\__,_|_| |_|_|\\_\\_|_| |_|\\__, | \n"
           "                                          __/ |     \n"
           "                                         |___/      \n");
    printf("    _________________________________________________________\n");
    while (fscanf(log, "%d", &luid) && fscanf(log, "%s", lfirstname) && fscanf(log, "%s", llastname) && fscanf(log, "%s", lusername) && fscanf(log, "%s", lpassword) && fscanf(log, "%f", &lbalance))
    {
        if(feof(log)){
            break;
        }
        if(uid == luid)
        {
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d",&choice);
            if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&deposit);
                    lbalance+=deposit;
                    fprintf(new_rec,"%d\n%s\n%s\n%s\n%s\n%f\n", luid, lfirstname, llastname, lusername, lpassword, lbalance);
                    load();
                }
            else if(choice == 2)
                {

                    printf("Enter the amount you want to Withdrawn:$ ");
                    scanf("%f",&withdrawn);
                    if(lbalance < withdrawn)
                        {
                            system("COLOR C");
                            printf("You don't have enough money\n");
                            fprintf(new_rec,"%d\n%s\n%s\n%s\n%s\n%f\n", luid, lfirstname, llastname, lusername, lpassword, lbalance);
                            system("pause");
                            system("CLS");

                            continue;
                        }
                    else
                        {
                        lbalance-=withdrawn;
                        fprintf(new_rec,"%d\n%s\n%s\n%s\n%s\n%f\n", luid, lfirstname, llastname, lusername, lpassword, lbalance);
                        printf("\n\nWithdrawn successfully!\n");
                        }
                }
        } else {
            fprintf(new_rec,"%d\n%s\n%s\n%s\n%s\n%f\n", luid, lfirstname, llastname, lusername, lpassword, lbalance);
        }
    }
    fclose(log);
    fclose(new_rec);
    remove("user.txt");
    rename("new_user.txt","user.txt");
    system("CLS");
    mainmenu(uid);
}
int shopping(uid)
{
    char username[20], password[20], lusername[20], lpassword[20], lfirstname[100], llastname[100];
    int luid, choice, items, amount;
    float lbalance, deposit, withdrawn;
    log = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\user.txt", "r");
    new_rec = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\new_user.txt", "a");
    system("COLOR B");
    printf("    _________________________________________________________ \n"
           "         _____ _                       _                      \n"
           "        / ____| |                     (_)                     \n"
           "       | (___ | |__   ___  _ __  _ __  _ _ __   __ _          \n"
           "        \\___ \\| '_ \\ / _ \\| '_ \\| '_ \\| | '_ \\ / _` |  \n"
           "        ____) | | | | (_) | |_) | |_) | | | | | (_| |         \n"
           "       |_____/|_| |_|\\___/| .__/| .__/|_|_| |_|\\__, |       \n"
           "                          | |   | |             __/ |         \n"
           "                          |_|   |_|            |___/          \n"
           "    _________________________________________________________ \n\n");


            printf("__________________________\n");
    printf("What do you want to buy?\n");
    printf("__________________________\n\n");
    printf("[1] Coca Cola(15B)        [2] Pepsi(15B)        [3] BrushTeeth(20B)\n"
           "[4] Chocolate(20B)        [5] Pencil Case(35B)  [6] Body Cream Care(100B)\n"
           "[7] Instant noodle(18B)   [8] Spices(5B)        [9] Candy(2B)\n"
           "[10] Bottle of Water(8B)  [11] Bread Row(55B)   [12] Liquid Paper(35B)\n"
           "\n"
           "[0] Calculate The Bill                          [99] Go to Option\n"
           "________________________________________________________________________\n");
    printf("_________________________________\n");

    while (fscanf(log, "%d", &luid) && fscanf(log, "%s", lfirstname) && fscanf(log, "%s", llastname) && fscanf(log, "%s", lusername) && fscanf(log, "%s", lpassword) && fscanf(log, "%f", &lbalance))
    {
        if(feof(log))
            {
            break;
            }
        if(luid == uid)
            {
                if(lbalance == 0 || price_buy > lbalance){
        int method;
        system("color c");
        printf("You can\'t buy anything! You need to have some money in your balance.\n");
        printf("What do you want to do? [1] Go to Banking [2] Go to Option : ");
        scanf("%d", &method);
        switch(method){
            case 1 :
                system("CLS");
                transcation(uid);
                break;
            case 2 :
                system("CLS");
                mainmenu(uid);
                break;
            default :
                system("CLS");
                shopping(uid);
        }
    }else{
        printf("What do you want : ");
        scanf("%d", &items);
    }
    if(items == 0){
        system("CLS");
        end_shop(uid);
    }else if(items > 12){
        if(items == 99){
            system("CLS");
            mainmenu(uid);
        }else{
            system("color c");
            printf("Out of range!");
            end_shop(uid);
        }
    }else{
        printf("What amount do you want? : ");
        scanf("%d", &amount);
    }
    if(items != "" && amount != ""){
        switch(items){
            case 1 :
                price_buy += (amount * 15);
                d_name[count_eiei] = "Coca Cola(15B)";
                d_price[count_eiei] = 15;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 2 :
                price_buy += (amount * 15);
                d_name[count_eiei] = "Pepsi(15B)";
                d_price[count_eiei] = 15;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 3 :
                price_buy += (amount * 20);
                d_name[count_eiei] = "BrushTeeth(20B)";
                d_price[count_eiei] = 20;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 4 :
                price_buy += (amount * 20);
                d_name[count_eiei] = "Chocolate(20B)";
                d_price[count_eiei] = 20;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 5 :
                price_buy += (amount * 35);
                d_name[count_eiei] = "Pencil Case(35B)";
                d_price[count_eiei] = 35;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 6 :
                price_buy += (amount * 100);
                d_name[count_eiei] = "Body Cream Care(100B)";
                d_price[count_eiei] = 100;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 7 :
                price_buy += (amount * 18);
                d_name[count_eiei] = "Instant noodle(18B)";
                d_price[count_eiei] = 18;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 8 :
                price_buy += (amount * 5);
                d_name[count_eiei] = "Spices(5B)";
                d_price[count_eiei] = 5;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 9 :
                price_buy += (amount * 2);
                d_name[count_eiei] = "Candy(2B)";
                d_price[count_eiei] = 2;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 10 :
                price_buy += (amount * 8);
                d_name[count_eiei] = "Bottle of Water(8B)";
                d_price[count_eiei] = 8;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 11 :
                price_buy += (amount * 55);
                d_name[count_eiei] = "Bread Row(55B)";
                d_price[count_eiei] = 55;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 12 :
                price_buy += (amount * 35);
                d_name[count_eiei] = "Liquid Paper(35B)";
                d_price[count_eiei] = 35;
                d_amount[count_eiei] = amount;
                count_eiei++;
                break;
            case 0 :
                end_shop(uid);
                break;
        }
    }
    end_shop(uid);
            }
    }


}

int end_shop(uid){ /* Do after shop */
    int method;
    printf("\nWhat do you want to do? [1] Buy Another Thing [2] Calculate : ");scanf("%d", &method);
    switch(method){
        case 1 :
            system("CLS");
            shopping(uid);
            break;
        case 2 :
            system("CLS");
            bill(uid);
            break;
        default :
            system("CLS");
            end_shop(uid);
    }
}

void bill(uid){ /* Bill after shop */
    char username[20], password[20], lusername[20], lpassword[20], lfirstname[100], llastname[100];
    int luid, choice, items, amount;
    float lbalance, deposit, withdrawn;
    log = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\user.txt", "r");
    new_rec = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\new_user.txt", "a");
    int i;
    printf("                                                             _______________ \n"
           "       _____          _       ____  _ _ _                   |               |\n"
           "      / ____|        | |     |  _ \\(_) | |                  |               |\n"
           "     | |     __ _ ___| |__   | |_) |_| | |                  |               |\n"
           "     | |    / _` / __| '_ \\  |  _ <| | | |                  |               |\n"
           "     | |___| (_| \\__ \\ | | | | |_) | | | |                  |               |\n"
           "      \\_____\\__,_|___/_| |_| |____/|_|_|_|                  |_______________|\n");
    printf("    _______________________________________________________________________________\n");
    printf("                Name            |        Amount        |        Summation        \n");
    printf("    _______________________________________________________________________________\n");
    for(i=0; i<count_eiei; i++){
        printf("    %2d. %22s    %11d            %12dB\n", i + 1, d_name[i], d_amount[i], d_amount[i]*d_price[i]);
    }
    printf("    _______________________________________________________________________________ \n");
    printf("                              Current Price(No Vat)    |%23dB  |\n", price_buy);
    int vat = price_buy * 7 / 100;
    int total = vat + price_buy;
    printf("                                             Vat 7%%    |%23dB  |\n", vat);
    price_buy = total;
    printf("                                              Total    |%23dB  |\n", price_buy);
    printf("Press Enter To Continue .....\n");
    int select = getch();
    if(select == 13){
        system("CLS");
    }else{
        system("CLS");
        bill(uid);
    }
}



int mainmenu(uid)
{
    system("COLOR A");
    int choice;
    printf("    ____________________________________________\n"
           "           ____        _   _                 \n"
           "          / __ \\      | | (_)               \n"
           "         | |  | |_ __ | |_ _  ___  _ __      \n"
           "         | |  | | '_ \\| __| |/ _ \\| '_ \\  \n"
           "         | |__| | |_) | |_| | (_) | | | |    \n"
           "          \\____/| .__/ \\__|_|\\___/|_| |_| \n"
           "                | |                          \n"
           "                |_|                          \n"
           "    ____________________________________________\n");
    printf("[1] Shopping       [2] Banking\n");
    printf("What do you want to do? : ");
    scanf("%d", &choice);
    if(choice == 1)
        {
            system("CLS");
            shopping(uid);
        }
    if(choice == 2)
        {
            system("CLS");
            transcation(uid);
        }
}
int registe()
{
    log = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\user.txt", "a");
    id = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\id.txt", "r");
    int uid;
    FILE *id2;
    id2 = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\id2.txt", "w");
    struct login l;
    printf("    _____________________________________________________   \n"
           "                                           _                \n"
           "            /\\                            | |              \n"
           "           /  \\   ___ ___ ___  _   _ _ __ | |_ ___         \n"
           "          / /\\ \\ / __/ __/ _ \\| | | | '_ \\| __/ __|     \n"
           "         / ____ \\ (_| (_| (_) | |_| | | | | |_\\__ \\      \n"
           "        /_/    \\_\\\___\\___\\___/ \\__,_|_| |_|\\__|___/  \n"
           "    _____________________________________________________ \n\n");
    fscanf(id, "%d", &uid);
    printf("Your id number is : %d\n", uid);
    printf("Enter First name : "); scanf("%s", l.fname);
    printf("Enter Last name : "); scanf("%s", l.lname);
    printf("Enter Username : "); scanf("%s", l.username);
    printf("Enter Password : "); scanf("%s", l.password);
    printf("Your current balance : %d B", l.balance);
    fprintf(log, "%d\n%s\n%s\n%s\n%s\n%f\n", uid, l.fname, l.lname, l.username, l.password, l.balance=0);
    fclose(log);
    fprintf(id2, "%d", uid+1);
    fclose(id);
    fclose(id2);
    remove("id.txt");
    rename("id2.txt","id.txt");
    printf("\n\nyour User name is UserID\n");
    printf("Now login with UserID and Password\n");
    system("pause");
    system("CLS");
    login();
}
int login()
{
    char username[20], password[20], lusername[20], lpassword[20], lfirstname[100], llastname[100];
    int luid;
    float lbalance;
    log = fopen("C:\\Users\\Acer\\Downloads\\Compressed\\Compro-project\\user.txt", "r");
    printf("    _____________________________________________________   \n"
           "                                           _                \n"
           "            /\\                            | |              \n"
           "           /  \\   ___ ___ ___  _   _ _ __ | |_ ___         \n"
           "          / /\\ \\ / __/ __/ _ \\| | | | '_ \\| __/ __|     \n"
           "         / ____ \\ (_| (_| (_) | |_| | | | | |_\\__ \\      \n"
           "        /_/    \\_\\\___\\___\\___/ \\__,_|_| |_|\\__|___/  \n"
           "    _____________________________________________________ \n\n");
    printf("UserID: ");
    scanf("%s", &username);
    printf("\nPassword: ");
    scanf("%s", &password);
    while (fscanf(log, "%d", &luid) && fscanf(log, "%s", lfirstname) && fscanf(log, "%s", llastname) && fscanf(log, "%s", lusername) && fscanf(log, "%s", lpassword) && fscanf(log, "%f", &lbalance))
    {
        if(strcmp(username, lusername) == 0 && strcmp(password, lpassword) == 0)
        {
            printf("WELCOME %s\n", lfirstname);
            system("pause");
            system("CLS");
            fclose(log);
            mainmenu(luid);
            break;
        } if(feof(log)) {
            printf("Please enter correct UserID and Password\n");
            system("pause");
            system("CLS");
            break;
        }
    }
    fclose(log);
}
int main()
{
    load_start();
    int choice;
    system("COLOR A");
    printf("    _____________________________________________________   \n"
           "                                           _                \n"
           "            /\\                            | |              \n"
           "           /  \\   ___ ___ ___  _   _ _ __ | |_ ___         \n"
           "          / /\\ \\ / __/ __/ _ \\| | | | '_ \\| __/ __|     \n"
           "         / ____ \\ (_| (_| (_) | |_| | | | | |_\\__ \\      \n"
           "        /_/    \\_\\\___\\___\\___/ \\__,_|_| |_|\\__|___/  \n"
           "    _____________________________________________________ \n\n");
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
