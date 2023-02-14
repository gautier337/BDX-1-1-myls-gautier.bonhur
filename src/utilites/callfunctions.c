/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** call functions
*/

#include "../../includes/my.h"

int call_simple(int argc, char **argv, int countd)
{
    if (argc - countd > 2) {
        argv = delete_first_argv(argc, argv);
        argv = sort_argv(argv, argc - 1, argc - 1);
        different_nb_of_path(argc, argv, 0, 0);
        return 0;
    }
    if (argc > 1 && argc - countd != 1) {
        ls_simple(get_path(argc, argv));
        return 0;
    }
    if (argc == 1 || argc - countd == 1) {
        ls_simple("./");
        return 0;
    }
}

int call_with_l(int argc, char **argv, int countd)
{
    if (argc - countd > 2) {
        argv = delete_first_argv(argc, argv);
        argv = sort_argv(argv, argc - 1, argc - 1);
        different_nb_of_path(argc, argv, 0, 1);
        return 0;
    }
    if (argc > 1 && argc - countd != 1) {
        ls_l(get_path(argc, argv));
        return 0;
    }
    if (argc == 1 || argc - countd == 1) {
        ls_l("./");
        return 0;
    }
}

int call_with_r(int argc, char **argv, int countd)
{
    if (argc - countd > 2) {
        argv = delete_first_argv(argc, argv);
        argv = sort_argv(argv, argc - 1, argc - 1);
        different_nb_of_path_r(argc, argv);
        return 0;
    }
    if (argc > 1 && argc - countd != 1) {
        ls_r(get_path(argc, argv));
        return 0;
    }
    if (argc == 1 || argc - countd == 1) {
        my_putstr(".:\n");
        repeat("src");
        return 0;
    }
}

struct_flags_t define_struct_int(int nb_arg, char *flags)
{
    struct struct_flags s;

    s.a = 0;
    s.d = 0;
    s.r = 0;
    s.l = 0;

    for (int i = 0; i < nb_arg && nb_arg != 8; i++) {
        s.a = (flags[i] == 'a') ? 1 : s.a;
        s.l = (flags[i] == 'l') ? 1 : s.l;
        s.r = (flags[i] == 'R') ? 1 : s.r;
        s.d = (flags[i] == 'd') ? 1 : s.d;
    }
    return s;
}

int call_functions(int argc, char **argv, char *flags, int countd)
{
    struct struct_flags s;
    int nb_arg = my_strlen(flags);
    s = define_struct_int(nb_arg, flags);

    if (s.d == 1)
        ls_d(argv, argc);
    if (s.l == 1 && s.a != 1 && s.r != 1 && s.d != 1)
        call_with_l(argc, argv, countd);
    if (s.a == 1 && s.l != 1 && s.r != 1 && s.d != 1)
        call_with_a(argc, argv, countd);
    if (s.r == 1 && s.a != 1 && s.l != 1 && s.d != 1)
        call_with_r(argc, argv, countd);
    if (s.r != 1 && s.a != 1 && s.l != 1 && s.d != 1)
        call_simple(argc, argv, countd);
}