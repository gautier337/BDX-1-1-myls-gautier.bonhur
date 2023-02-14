/*
** EPITECH PROJECT, 2021
** ls_without_args
** File description:
** ls
*/

#include "../../includes/my.h"

char **get_argv(char const *path)
{
    int stop = 0;

    DIR *dd = opendir(path);
    if (dir_exist(dd, path) == 84)
        stop = 1;
    struct dirent *iss;
    int i = 0;
    int argc = count_argc(path);

    char **list = malloc(sizeof(char *) + malloc_simple(path));

    while (iss = readdir(dd)) {
        if (iss->d_name[0] != '.' && stop != 1) {
            list[i] = malloc(my_strlen(iss->d_name));
            list[i] = iss->d_name;
            i++;
        }
    }
    return list;
}

void print_new_path(char *new_path)
{
    my_putstr("newpath: ");
    my_putstr(new_path);
    my_putchar('\n');
}

void print_repeat(char **argv, int i)
{
    my_putstr(argv[i]);
    my_putstr(":\n");
}

void repeat(char *path)
{
    int dir = 0;
    char **argv = get_argv(path);
    int argc = count_argc(path);
    int argi = 0;
    struct stat fileStat;

    ls_r(path);
    if (path[0] == '.')
        path = path + 2;
    for (int i = 0; i < argc; i++) {
        stat(argv[i], &fileStat);
        dir = S_ISDIR(fileStat.st_mode);
        if (dir == 1) {
            print_repeat(argv, i);
            char *new_path = malloc(my_strlen(argv[i] + my_strlen(path)));
            new_path = my_strcat(new_path, "/");
            new_path = my_strcat(new_path, argv[i]);
            print_new_path(new_path);
        }
    }
}

int ls_r(const char *path)
{
    DIR *d = opendir(path);
    if (dir_exist(d, path) == 84)
        return 84;
    struct dirent *is;
    int i = 0;
    int argc = count_argc(path);

    char **list = malloc(sizeof(char *) + malloc_simple(path));

    while (is = readdir(d)) {
        if (is->d_name[0] != '.') {
            list[i] = malloc(my_strlen(is->d_name));
            list[i] = is->d_name;
            i++;
        }
    }
    closedir(d);
    list = sort_argv(list, argc, argc);
    display_simple(list, argc);
    return 0;
}
