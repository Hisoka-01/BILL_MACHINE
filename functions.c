// max_Limit will defined in main program using #define

#include "functions.h"

void renew()
{
    int max_Limit;
    FILE *file = NULL;
    file = fopen("priceList.txt", "w");
    char name[15];
    float price;
    if (file == NULL)
    {
        printf("File does not exist\n");
    }
    else
    {
        printf("\n Enter the name of the items with their price to add in the fresh pricelist \n");
        char exit[] = "exit";
        int i = 0;
        scanf("%s %f", name, &price);
        while (i < max_Limit && strcmp(name, exit) != 0)
        {
            fprintf(file, "%s %.2f\n", name, price);
            scanf("%s %f", name, &price);
            i++;
        }
    }
    fclose(file);
}

void price_add()
{
    int max_Limit;
    FILE *file = NULL;
    file = fopen("priceList.txt", "a");
    char name[15];
    float price;
    if (file == NULL)
    {
        printf("File does not exist\n");
    }
    else
    {
        printf("\n Enter the name of the items with their price to add in the pricelist \n");
        char exit[] = "exit";
        int i = 0;
        scanf("%s %f", name, &price);
        while (i < max_Limit && strcmp(name, exit) != 0)
        {
            fprintf(file, "%s %.2f\n", name, price);
            scanf("%s %f", name, &price);
            i++;
        }
    }
    fclose(file);
}

void price_View()
{
    FILE *file = NULL;
    file = fopen("priceList.txt", "r");
    char name[15];
    float price;
    if (file == NULL)
    {
        printf("File does not exist\n");
    }
    else
    {
        printf("\n Items in the price list with thier price : \n");
        while (fscanf(file, "%s %f", name, &price) != EOF)
        {
            printf("Item: %s Price : %.2f\n", name, price);
        }
    }
    fclose(file);
}

float retrieve(char *ptr)
{
    FILE *file = NULL;
    file = fopen("priceList.txt", "r");
    char name[15];
    float price = -1.0f;
    if (file == NULL)
    {
        printf("File does not exist\n");
        return -1;
    }
    else
    {
        while (fscanf(file, "%s %f", name, &price) != EOF)
        {
            if (strcmp(name, ptr) == 0)
            {
                fclose(file);
                return price;
            }
        }
    }
    printf("ERROR : Item not found\n");
    fclose(file);
    return -1;
}

void add(struct Items check[], int *total)
{
    printf("\n Enter the items to add in the list \n");
    int max_Limit;
    char name[15];
    char exit[] = "exit";
    scanf("%s", name);
    int z = -1;
    while (*total < max_Limit && strcmp(name, exit) != 0)
    {
        z = retrieve(name);
        if (z > 0)
        {
            check[*total].price = z;
            strcpy(check[(*total)].name, name);
            (*total)++;
        }
        scanf("%s", name);
    }
}

void display(struct Items check[], int *count)
{
    printf("\n Items in the checklist : \n");
    for (int i = 0; i < *count; i++)
    {
        printf("Items : %s and price : %.2f\n", check[i].name, check[i].price);
    }
}

void del(struct Items check[], int *total)
{
    printf("\n Enter the name of the item you wish to delete\n");
    char str[15];
    scanf("%s", str);
    int i, j;
    i = j = 0;
    while (i < *total && j < *total)
    {
        if (strcmp(check[i].name, str) == 0)
        {
            strcpy(check[j].name, check[j + 1].name);
            check[j].price = check[j+1].price;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    if (i < *total)
    {
        strcpy(check[--(*total)].name, "\0");
        check[(*total)].price = -1;
    }
    else
    {
        printf("There is no such item in the checklist\n");
    }
}

void upload(struct Items item[], int *count)
{
    FILE *file = NULL;
    file = fopen("Checklist.txt", "w");
    if (file == NULL)
    {
        printf("File does not exist\n");
    }
    else
    {
        int i = 0;
        while (i < *count)
        {
            fprintf(file, "%s %.2f\n", item[i].name, item[i].price);
            i++;
        }
        printf("\n Upload Complete \n");
    }
    fclose(file);
}

void list_View()
{
    FILE *file = NULL;
    file = fopen("Checklist.txt", "r");
    char name[15];
    float price;
    if (file == NULL)
    {
        printf("File does not exist\n");
    }
    else
    {
        printf("\n Items in the checklist with their price : \n");
        while (fscanf(file, "%s %f", name, &price) != EOF)
        {
            printf("Item: %s Price : %.2f\n", name, price);
        }
    }
    fclose(file);
}