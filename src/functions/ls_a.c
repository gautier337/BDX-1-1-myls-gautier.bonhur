/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** -a
*/

#include "../../includes/my.h"

int malloc_simple_a(const char *path)
{
    DIR *d = opendir(path);
    struct dirent *is;
    int x = 0;

    while (is = readdir(d)) {
        x = x + my_strlen(is->d_name);
    }
    closedir(d);
    return x + 1;
}

int count_argc_a(char const *path)
{
    DIR *d = opendir(path);
    struct dirent *is;
    int argc = 0;

    while (is = readdir(d))
        argc += 1;
    closedir(d);
    return argc;
}

void ls_a_directory(char const *path)
{
    DIR *d = opendir(path);
    struct dirent *is;
    int i = 0;
    int argc = count_argc_a(path);

    char **list = malloc(malloc_simple_a(path));

    while (is = readdir(d)) {
        list[i] = malloc(my_strlen(is->d_name));
        list[i] = is->d_name;
        i++;
    }
    closedir(d);
    list = sort_argv(list, argc, argc);
    display_simple(list, argc);
}

int ls_a(const char *path)
{
    struct stat ee;
    stat(path, &ee);

    if (S_ISREG(ee.st_mode)) {
        my_putstr(path);
        my_putchar('\n');
        return 0;
    }
    if (S_ISDIR(ee.st_mode)) {
        ls_a_directory(path);
        return 0;
    }
    my_putstr("my_ls: cannot access '");
    my_putstr(path);
    my_putstr("': No such file or directory\n");
    return 84;
}
