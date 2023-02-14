/*
** EPITECH PROJECT, 2021
** main
** File description:
** my_ls
*/

#include "../includes/my.h"

int call_ls_a_or_ls(char const *path, int a, int l)
{
    if (a == 1) {
        ls_a(path);
        return 0;
    }
    if (l == 1) {
        ls_l(path);
        return 0;
    }
    ls_simple(path);
}

void display_error(char *argv)
{
    my_putstr("my_ls: cannot access '");
    my_putstr(argv);
    my_putstr("': No such file or directory\n");
}

void different_nb_of_path(int argc, char **argv, int a, int l)
{
    char *path;
    int y = 0;
    const struct stat empty;
    struct stat s;
    for (int x = 0; x < argc - 1; x++) {
        stat(argv[x], &s);
        if (argv[x][0] != '-' && (S_ISREG(s.st_mode) || S_ISDIR(s.st_mode))) {
            path = argv[x];
            y = 1;
            my_putstr(path);
            my_putstr(":\n");
            call_ls_a_or_ls(path, a, l);
        } else if ((argv[x][0] != '-')  &&
        !(S_ISREG(s.st_mode) || S_ISDIR(s.st_mode)))
            display_error(argv[x]);
        if ((argc - x) > 2 && y == 1)
            my_putchar('\n');
        s = empty;
    }
}

char **delete_first_argv(int argc, char **argv)
{
    for (int i = 0; i < argc - 1; i++)
        argv[i] = argv[i + 1];
    argv[argc - 1] = '\0';

    return argv;
}

int main(int argc, char **argv)
{
    int count_d = count_dash(argc, argv);
    char *flags;

    if (argc > 1 && count_d != 0)
        flags = get_flags(argc, argv, count_d);
    else
        flags = "xxxxxxxx";
    call_functions(argc, argv, flags, count_d);

    return 0;
}
