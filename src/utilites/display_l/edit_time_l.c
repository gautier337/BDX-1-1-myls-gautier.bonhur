/*
** EPITECH PROJECT, 2021
** display
** File description:
** edit_time_l
*/

#include "../../../includes/my.h"

char edit_ls_l(char *string)
{
    for (int i = 4; i < 16; i++)
        my_putchar(string[i]);
}