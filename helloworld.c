#include <stdio.h>
#include "tools.h"

void main()
{
    char *arr[] = {"test1", "test2"};
    int size = sizeof arr / sizeof arr[0];
    printf("Hello, World", arr[10]);
    getchar();
}