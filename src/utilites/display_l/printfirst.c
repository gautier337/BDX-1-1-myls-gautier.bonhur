/*
** EPITECH PROJECT, 2021
** display
** File description:
** printfirst
*/

#include "../../../includes/my.h"

void printfirst(const char *path)
{
    int count = 0;

    for (int i = 0; i < my_strlen(path); i++)
        if (path[i] == '/' && path[i + 1] != '\0')
            count++;
    for (int i = 0; i < count;) {
        if (path[0] == '/')
            i++;
        path++;
    }
    for (int i = 0; i < my_strlen(path); i++)
        if (path[i] != '/')
            my_putchar(path[i]);
}