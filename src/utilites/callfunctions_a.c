/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** call_functions_a
*/

#include "../../includes/my.h"

int call_with_a(int argc, char **argv, int countd)
{
    if (argc - countd > 2) {
        argv = delete_first_argv(argc, argv);
        argv = sort_argv(argv, argc - 1, argc - 1);
        different_nb_of_path(argc, argv, 1, 0);
        return 0;
    }
    if (argc > 1 && argc - countd != 1) {
        ls_a(get_path(argc, argv));
        return 0;
    }
    if (argc == 1 || argc - countd == 1) {
        ls_a("./");
        return 0;
    }
}