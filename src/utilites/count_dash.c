/*
** EPITECH PROJECT, 2021
** count_dash
** File description:
** my_ls
*/

int count_dash(int argc, char **argv)
{
    int counter = 0;

    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-')
            counter++;
    }
    return counter;
}
