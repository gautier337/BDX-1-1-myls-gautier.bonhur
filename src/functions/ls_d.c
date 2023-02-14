/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** d
*/

#include "../../includes/my.h"

void condition_ls_d(char **argv, int i, int nb_to_print)
{
    if (argv[i][0] != '-' && nb_to_print != 1) {
        my_putstr(argv[i]);
        my_putchar(' ');
    }
    if (argv[i][0] != '-' && nb_to_print == 1) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
}

void ls_d(char **argv, int argc)
{
    int nb_to_print = 0;

    if (argc == 2) {
        my_putstr(".\n");
    }
    for (int i = 0; i < argc; i++)
        if (argv[i][0] != '-' && argv[i][0] != '.')
            nb_to_print++;
    if (argc > 2)
        for (int i = 1; i < argc; i++, nb_to_print--)
            condition_ls_d(argv, i, nb_to_print);
}