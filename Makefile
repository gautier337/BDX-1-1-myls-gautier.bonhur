##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile
##

SRC	=	src/main.c \
		src/functions/ls_simple.c \
		src/functions/ls_l.c \
		src/functions/ls_a.c \
		src/functions/ls_r.c \
		src/functions/ls_d.c \
		src/lib/my_put_nbr.c \
		src/lib/my_putchar.c \
		src/lib/my_putstr.c \
		src/lib/my_strcmp.c \
		src/lib/my_strlen.c \
		src/lib/my_strcat.c \
		src/utilites/sort_argv.c \
		src/utilites/count_dash.c \
		src/utilites/ls_r_different_nbr_of_path.c \
		src/utilites/get_flags.c \
		src/utilites/get_path.c \
		src/utilites/display/display_simple.c \
		src/utilites/display_l/display_l.c \
		src/utilites/display_l/display_l_total.c \
		src/utilites/display_l/edit_time_l.c \
		src/utilites/display_l/printfirst.c \
		src/utilites/callfunctions.c \
		src/utilites/callfunctions_a.c \
		src/errors/error_handler.c

SRC_TESTS =

NAME = my_ls

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)
	rm -f a.out

fclean: clean
	rm -f $(NAME)

re: fclean all