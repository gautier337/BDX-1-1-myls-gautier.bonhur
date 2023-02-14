/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** str_cmp
*/

int my_strlen (char const *str);

int my_strcmp (char const *s1, char const *s2)
{
    int i = 0;
    int count;
    int value = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        count = s1[i] - s2[i];
        if (count < 0) {
            return 0;
        } else if (count > 0) {
            return 1;
        } else {
            i++;
        }
    }
    if (my_strlen(s1) > my_strlen(s2)) {
        return 1;
    } else if (my_strlen(s1) > my_strlen(s2)) {
        return 0;
    }
    return 84;
}
