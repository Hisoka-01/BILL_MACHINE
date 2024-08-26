#include <stdio.h>
#include <string.h>

const int max_Limit = 20;

struct Items
{
    char name[20];
    float price;
};

void renew()
{
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
    char name[15];
    char exit[] = "exit";
    scanf("%s", name);
    while (*total < max_Limit && strcmp(name, exit) != 0)
    {
        strcpy(check[(*total)].name, name);
        check[*total].price = retrieve(name);
        (*total)++;
        scanf("%s", name);
    }
}

void display(struct Items check[], int *count)
{
    printf("Items in the checklist : \n");
    for (int i = 0; i < *count; i++)
    {
        printf("Items : %s and price : %.2f\n", check[i].name, check[i].price);
    }
}

int main(int argc, char const *argv[])
{
    struct Items checklist[20];
    int total = 0;
    printf("Enter the item with their price to put into price list\n");
    renew();
    price_View();
    printf("Enter the elements for the checklist\n");
     add(checklist, &total);
     display(checklist, &total);

    return 0;
}
