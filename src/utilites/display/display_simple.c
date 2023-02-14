/*
** EPITECH PROJECT, 2021
** ls
** File description:
** display_simple
*/

#include "../../../includes/my.h"

int display_simple_file(const char *path)
{
    my_putstr(path);
    my_putchar('\n');
    return 0;
}

int display_simple(char **argv, int argc)
{
    if (argc == 0)
        return 0;
    for (int w = 0; w < argc; w++) {
        my_putstr(argv[w]);
        if (w != argc - 1)
            my_putchar(' ');
    }
    my_putchar('\n');
    return 0;
}