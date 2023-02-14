/*
** EPITECH PROJECT, 2021
** ls_without_args
** File description:
** ls
*/

#include "../../includes/my.h"

int malloc_simple(const char *path)
{
    DIR *d = opendir(path);
    struct dirent *is;
    int x = 0;

    while (is = readdir(d)) {
        if (is->d_name[0] != '.') {
            x = x + my_strlen(is->d_name);
        }
    }
    closedir(d);
    return x + 1;
}

int count_argc(char const *path)
{
    DIR *d = opendir(path);
    struct dirent *is;
    int argc = 0;
    int a = 0;

    while (is = readdir(d))
        if (is->d_name[0] != '.')
            argc += 1;
    closedir(d);
    return argc;
}

int ls_simple(const char *path)
{
    struct stat ee;
    stat(path, &ee);

    if (S_ISREG(ee.st_mode)) {
        display_simple_file(path);
        return 0;
    }
    if (S_ISDIR(ee.st_mode)) {
        DIR *d = opendir(path);
        int argc = count_argc(path);
        char **list = define_list(path, d);
        closedir(d);
        list = sort_argv(list, argc, argc);
        display_simple(list, argc);
        return 0;
    }
    my_putstr("my_ls: cannot access '");
    my_putstr(path);
    my_putstr("': No such file or directory\n");
    return 84;
}
