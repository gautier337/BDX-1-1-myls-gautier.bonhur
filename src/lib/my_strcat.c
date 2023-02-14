/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** my_strcapitalize
*/

#include "../../includes/my.h"

int my_strlen (char const *str);

char *my_strcatt(char const *src, char *dest)
{
    int len_src = my_strlen(src);
    int i;
    char *tmp = src;
    char *new = malloc(my_strlen(dest) + my_strlen(src) + 1);

    for (int x = 0; x < len_src; x++)
        new[x] = tmp[x];
    i = 0;
    while (dest[i] != '\0') {
        new[len_src + i] = dest[i];
        i++;
    }
    new[len_src + i] = '\0';
    return new;
}

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int i;
    char *new = malloc(my_strlen(dest) + my_strlen(src) + 1);
    new = dest;

    for (i = 0; src[i] != '\0'; i++)
        new[dest_len + i] = src[i];
    new[dest_len + i] = '\0';

    return new;

}
