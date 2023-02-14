/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** get_flags
*/

#include "../../includes/my.h"

char *check_bash(char **argv, int i)
{
    int lenght = 0;
    int i_flag = 0;
    char *to_add = malloc(5);

    lenght = my_strlen(argv[i]);
    for (; i_flag < lenght; i_flag++)
        if (argv[i][i_flag + 1] > 'A' && argv[i][i_flag + 1] < 'z')
            to_add[i_flag] = argv[i][i_flag + 1];
    return to_add;
}

char *get_flags(int argc, char **argv, int count_dash)
{
    int counter = 0;
    char *flags = malloc(count_dash * 2 + 1);

    for (int i = 0; i < argc; i++)
        if (argv[i][0] == '-')
            flags = my_strcat(flags, check_bash(argv, i));
    return flags;
}
