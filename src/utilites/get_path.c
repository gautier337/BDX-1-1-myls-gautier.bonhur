/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** get_path
*/

#include "../../includes/my.h"

char *get_path(int argc, char **argv)
{
    char *path;
    for (int i = 0; i < argc; i++)
        if (argv[i][0] != '-' && i != 0) {
            path = argv[i];
            return path;
        }
}