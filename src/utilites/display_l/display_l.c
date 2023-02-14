/*
** EPITECH PROJECT, 2021
** display
** File description:
** display_my_ls
*/

#include "../../../includes/my.h"

void display_perm(char *argv)
{
    struct stat fileStat;
    struct stat empty;
    stat(argv, &fileStat);
    my_putstr((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    my_putstr((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((fileStat.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    fileStat = empty;
}

void display_size(char *path)
{
    struct stat fileStat;
    stat(path, &fileStat);
    my_put_nbr(fileStat.st_size);
}

void display_uid(char *path)
{
    struct stat fileStat;
    stat(path, &fileStat);
    struct group *grp = getgrgid(fileStat.st_uid);
    struct passwd *pws = getpwuid(fileStat.st_uid);
    my_putstr(pws->pw_name);
    my_putchar(' ');
    my_putstr(grp->gr_name);
}

int display_single_l(char *result)
{
    display_perm(result);
    my_putchar(' ');
    my_put_nbr(1);
    my_putchar(' ');
    display_uid(result);
    my_putchar(' ');
    my_putchar(' ');
    display_size(result);
    my_putchar(' ');
    display_date(result);
    my_putchar(' ');
    my_putstr(result);
    my_putchar('\n');
}

int display_l(char **argv, int argc, const char *path)
{
    for (int i = 0; i < argc; i++) {
        char *result = my_strcatt(path, argv[i]);
        display_perm(result);
        my_putchar(' ');
        my_put_nbr(1);
        my_putchar(' ');
        display_uid(result);
        my_putchar(' ');
        my_putchar(' ');
        display_size(result);
        my_putchar(' ');
        display_date(result);
        my_putchar(' ');
        printfirst(result);
        my_putchar('\n');
    }
    return 0;
}
