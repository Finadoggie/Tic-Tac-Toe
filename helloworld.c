#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char* name;
    char* category;
} ITEM;

void changeString(char* str)
{
    fflush(stdin);
    fgets(str, 99, stdin);
    for (int i = 0; i < 99; i++)
    {
        str[i] = (str[i] == 0x0a ? 0x00 : str[i]);
    }
    return;
}

void printList(ITEM* item, int len)
{
    if(len == 0)
    {
        printf("Your list is empty!");
        return;
    }
    printf("\e[1;1H\e[2JYour list is %d item(s)!\n");
    for(int i = 0; i < len; i++) printf("\nItem #%d\n  Name: %s\n  Category: %s\n", i, item[i].name, item[i].category);
    fflush(stdin);
    getchar();
    return;
}

int addItemToList(ITEM* item, int len)
{
    len += 1;
    
    item = realloc(item, (len) * 16);
    printf("\e[1;1H\e[2JNew item name: ");
    item[len - 1].name = (char*)malloc(99);
    changeString(item[len - 1].name);
    
    printf("New item category: ");
    item[len - 1].category = (char*)malloc(99);
    changeString(item[len - 1].category);
    printf("Item %s has been added!", item[len - 1].name);
    fflush((stdin));
    getchar();
    return len;
}

char printOptions()
{
    char* options[] = { 
        "Add item to list",
        "Print List",
        "Fuck off"
    };
    // printf("%d", sizeof(options));
    int len = sizeof(options) / 8;
    for(int i = 0; i < len; i++) printf("[%d] %s\n", i, options[i]);
    fflush(stdin);
    return fgetchar();
}

int main()
{
    ITEM* item = malloc(8);
    // printf("%d", sizeof(item));

    int len = 0;
    char choice;

    while (1)
    {
        printf("\e[1;1H\e[2JWhat would you like to do?\n");
        choice = printOptions();
        printf("Len: %d\n", len);
        
        if(choice == '0') len = addItemToList(item, len);
        if(choice == '1') printList(item, len);
        if(choice == '2') return 0;
    }
}