/*
** EPITECH PROJECT, 2021
** ls_without_args
** File description:
** ls
*/

#include "../../includes/my.h"

void printtotal(char **list, int argc, const char *path)
{
    my_putstr("total ");
    my_put_nbr(display_total(list, argc, path));
    my_putchar('\n');
}

void call_function(char **list, int argc, const char *path)
{
    list = sort_argv(list, argc, argc);
    printtotal(list, argc, path);
    display_l(list, argc, path);
}

char **define_list(const char *path, DIR *d)
{
    struct dirent *is;
    int i = 0;

    char **list = malloc(sizeof(char *) + malloc_simple(path));

    while (is = readdir(d))
        if (is->d_name[0] != '.') {
            list[i] = malloc(my_strlen(is->d_name));
            list[i] = is->d_name;
            i++;
        }
    return list;
}

int ls_l(const char *path)
{
    struct stat ee;
    stat(path, &ee);

    if (S_ISREG(ee.st_mode)) {
        display_single_l(path);
        return 0;
    }
    if (S_ISDIR(ee.st_mode)) {
        DIR *d = opendir(path);
        int argc = count_argc(path);
        char **list = define_list(path, d);
        closedir(d);
        call_function(list, argc, path);
        return 0;
    }
    my_putstr("my_ls: cannot access '");
    my_putstr(path);
    my_putstr("': No such file or directory\n");
    return 84;
}
