#include <stdio.h>

struct item {
    char* name;
    char* category;
};

void printItem(struct item i) 
{
    printf("Name: %s\nCategory: %s\n", i.name, i.category);
}

void main()
{
    struct item items = { "John Doe", "Male" };
    printf("Type: %s", items);
}