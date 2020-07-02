/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

#ifndef ABS_MAC
#define ABS(value) ((value) < (0) ? ((value) * (-1)) : (value))
#endif /* !ABS_MAC */

/* ------------------------------- GENERATOR ------------------------------- */

/* ----------- STACK ----------- */

typedef struct stack
{
    int x;
    int y;
    struct stack *down;
} stack_t;

stack_t *new_stack(void);
int is_empty_stack(stack_t *s_stack);
stack_t *push_stack(stack_t *s_stack, int x, int y);
stack_t *pop_stack(stack_t *s_stack);
stack_t *clear_stack(stack_t *s_stack);
void print_stack(stack_t *s_stack);

/* ----------- MAP ----------- */

void print_map(char **map);
void free_map(char **map);
char **create_map(int x, int y);

/* ----------- ALGO's ----------- */

char **iterative_backtracker(int x, int y, int ac);
void braid_maze(char **map, int ac, int y);
int my_solver(char **maze);

/* -------------------------------- SOLVER -------------------------------- */

/* ------------ LOAD_MAZE ------------ */

char **load_file_in_mem(char *av);
void print_map(char **map);
void free_map(char **map);
char *get_next_line(int fd);
void format_map(char **maze);

/* ------------ DEAD_END_FILLING ------------ */

void dead_end_filling(char **maze);

/* ------------ QUEUE ------------ */

typedef struct node_queue
{
    int x;
    int y;
    struct node_queue *parent;
    struct node_queue *next;
    struct node_queue *back;
} queue_node_t;

typedef struct queue
{
    int length;
    queue_node_t *last;
    queue_node_t *first;
} queue_t;

queue_t *new_queue(void);
int is_empty_queue(queue_t *li);
queue_node_t *new_queue_node(queue_node_t *parent, int x, int y);
queue_t *push_back_queue(queue_t *li, queue_node_t *parent, int x, int y);
queue_t *pop_front_queue(queue_t *li);
queue_t *clear_queue(queue_t *li);
queue_t *dequeue_front(queue_t *li, queue_t **dequeue);

/* ------------ BREADTH_FIRST_SEARCH ------------ */

int breadth_first_search(char **maze);

#endif /* !MY_H_ */