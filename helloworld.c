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
    struct item item1 = { "John Doe", "Male" };
    printItem(item1);
}