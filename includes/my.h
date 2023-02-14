/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** my_ls_header
*/

#ifndef my
    #define my

    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <unistd.h>
    #include <pwd.h>
    #include <time.h>
    #include <grp.h>

typedef struct struct_flags {
    int a;
    int r;
    int l;
    int d;
} struct_flags_t;

int my_strcmp (char const *s1, char const *s2);
int my_strlen (char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);

int display_simple(char **argv, int argc);
int display_simple_file(const char *path);
char **sort_argv(char **argv, int argc, int n);
int count_dash(int argc, char **argv);
int count_argc(char const *path);
int malloc_simple(const char *path);
int call_with_a(int argc, char **argv, int countd);

int ls_simple(const char *path);
int ls_a(const char *path);
int ls_l(const char *path);
int ls_r(const char *path);

void repeat(char *path);

char edit_ls_l(char *string);
int display_l(char **argv, int argc, const char *path);
int display_total(char **argv, int argc, char const *path);
void display_date(char *path);
int display_single_l(char *result);
void printfirst(const char *path);
char **define_list(const char *path, DIR *d);

void different_nb_of_path_r(int argc, char **argv);
char *get_path(int argc, char **argv);
void ls_d(char **argv, int argc);
char *get_flags(int argc, char **argv, int count_dash);
int dir_exist(DIR *d, const char *path);
char *my_strcat(char *dest, char const *src);
char *my_strcatt(char const *src, char *dest);
int call_functions(int argc, char **argv, char *flags, int countd);
char **delete_first_argv(int argc, char **argv);
void different_nb_of_path(int argc, char **argv, int a, int l);

#endif