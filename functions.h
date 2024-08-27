// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Struct definition
struct Items
{
    char name[20];
    float price;
};

// Function prototypes
void renew();
void price_add();
void price_View();
float retrieve(char *ptr);
void add(struct Items check[], int *total);
void display(struct Items check[], int *count);
void del(struct Items check[], int *total);
void upload(struct Items item[], int *count);
void list_View();

// Add other necessary includes and definitions
#include <stdio.h>
#include <string.h>

#endif // FUNCTIONS_H