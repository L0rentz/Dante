##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	generator

CC	=	gcc

SRC	=	src/main.c \
		src/stack_push_clear.c \
		src/stack_new_print.c \
		src/iterative_backtracker.c \
		src/braid_maze.c \
		src/map.c \
		src/breadth_first_search.c \
		src/dequeue.c \
		src/queue.c \
		src/dead_end_filling.c \
		src/solver.c \

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
