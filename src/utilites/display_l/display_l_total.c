/*
** EPITECH PROJECT, 2021
** display_total_l
** File description:
** my_ls
*/

#include "../../../includes/my.h"

void display_date(char *path)
{
    struct stat fileStat;
    stat(path, &fileStat);
    char time[16];
    edit_ls_l(ctime(&fileStat.st_mtim));
}

int display_total(char **argv, int argc, char const *path)
{
    struct stat fileStat_;
    int result = 0;
    for (int i = 0; i < argc; i++) {
        stat("./includes", &fileStat_);
        result = result + fileStat_.st_blocks / 2;
    }
    return result;
}