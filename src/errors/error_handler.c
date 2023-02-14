/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** error handler
*/

#include "../../includes/my.h"

int dir_exist(DIR *d, const char *path)
{
    int i = 0;
    struct stat ee;

    int file = stat(path, &ee);
    if (d == NULL && file == - 1) {
        my_putstr("my_ls: cannot access '");
        my_putstr(path);
        my_putstr("': No such file or directory\n");
        return 84;
    }
}