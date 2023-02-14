/*
** EPITECH PROJECT, 2021
** sort_argv
** File description:
** my_ls
*/

#include "../../includes/my.h"

char **sort_argv(char **argv, int argc, int n)
{
    if (n == 0)
        return argv;
    int a = 0;
    for (; a < argc - 1; a++) {
        if (my_strcmp(argv[a], argv[a + 1]) == 1) {
            char *tmp = argv[a];
            argv[a] = argv[a + 1];
            argv[a + 1] = tmp;
        }
    }
    sort_argv(argv, argc, n - 1);
}
