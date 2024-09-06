#include "functions.h"   // Include the header file for declarations

//have to use gcc to compile both programs.c and functions.c at once and then we can run the program 

#define max_Limit 20

void welcome()
{
    printf("\n Choose Option : \n");
    printf(" new - Renew ur pricelist \n");
    printf(" add_price - add in ur pricelist \n");
    printf(" price - View ur pricelist\n");
    printf(" add - Add items in ur list \n");
    printf(" list - View ur list \n");
    printf(" del - Delete items in ur list\n");
    printf(" update - Upload ur list to ur checklist\n");
    printf(" view - View ur checklist\n");
    printf(" options - Review the list\n");
    printf(" end - to end the program\n");
    printf("Enter ur choice  : ");
}

int main(int argc, char const *argv[])
{
    printf("Hello my friend, how are you\n");
    printf("Prolly happy cause u have to go to the market to buy stuff amd get a glimpse of some pretty girls  \n");
    printf("HUI HUI HUI HUI\n");

    struct Items checklist[max_Limit];
    int total = 0;
    char choice[10];

    welcome();

    scanf("%s", &choice);

    while (strcmp(choice, "end") != 0)
    {
        if (strcmp(choice, "new") == 0)
        {
            renew();
        }
        else if (strcmp(choice, "add_price") == 0)
        {
            price_add();
        }
        else if (strcmp(choice, "price") == 0)
        {
            price_View();
        }
        else if (strcmp(choice, "add") == 0)
        {
            add(checklist, &total);
        }
        else if (strcmp(choice, "list") == 0)
        {
            display(checklist, &total);
        }
        else if (strcmp(choice, "del") == 0)
        {
            del(checklist, &total);
        }
        else if (strcmp(choice, "update") == 0)
        {
            upload(checklist, &total);
        }
        else if (strcmp(choice, "view") == 0)
        {
            list_View();
        }
        else if (strcmp(choice, "options") == 0)
        {
            welcome();
        }
        else
        {
            printf("Error : Invaild choice entered\n Retry\n");
        }
        printf("\nEnter end if u wish to exit or input other options to continue\n");
        scanf("%s", &choice);
    }

    return 0;
}
