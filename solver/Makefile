##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	solver

CC	=	gcc

SRC	=	src/main.c \
		src/get_next_line.c \
		src/map.c \
		src/dead_end_filling.c \
		src/breadth_first_search.c \
		src/queue.c \
		src/dequeue.c \
		src/a_star.c \
		src/successors.c \
		src/dlist_a_star_utils.c \
		src/dlist.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-I./include -g3 -O3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
