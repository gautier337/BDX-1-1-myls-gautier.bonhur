/*
** EPITECH PROJECT, 2021
** different_nbr_of_path
** File description:
** my_lsR
*/

#include "../../includes/my.h"

void different_nb_of_path_r(int argc, char **argv)
{
    char *path;
    int y = 0;

    for (int x = 0; x < argc - 1; x++) {
        if (argv[x][0] != '-') {
            path = argv[x];
            y = 1;
            my_putstr(path);
            my_putstr(":\n");
            ls_r(path);
        }
        if ((argc - x) > 2 && y == 1)
            my_putchar('\n');
    }
}