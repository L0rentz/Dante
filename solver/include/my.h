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

#ifndef READ_SIZE
#define READ_SIZE (100000)
#endif /* !GNL*/

#ifndef ABS_MAC
#define ABS(value) ((value) < (0) ? ((value) * (-1)) : (value))
#endif /* !ABS_MAC */

/* ------------ !LOAD_MAZE ------------ */

char **load_file_in_mem(char *av);
void print_map(char **map);
void free_map(char **map);
char *get_next_line(int fd);
void format_map(char **maze);

/* ------------ !DEAD_END_FILLING ------------ */

void dead_end_filling(char **maze);

/* ------------ !QUEUE ------------ */

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

/* ------------ !BREADTH_FIRST_SEARCH ------------ */

void breadth_first_search(char **maze);

/* ------------ !DLIST ------------ */

typedef struct info_s
{
    int g;
    int h;
    int f;
    int x;
    int y;
} info_t;

typedef struct dlist_node_s
{
    info_t info;
    struct dlist_node_s *parent;
    struct dlist_node_s *back;
    struct dlist_node_s *next;
} dlist_node_t;

typedef struct dlist_s
{
    int length;
    struct dlist_node_s *begin;
    struct dlist_node_s *end;
} dlist_t;

dlist_t *new_list(void);
int is_empty_list(dlist_t *li);
dlist_node_t *new_dlist_node(info_t infos, dlist_node_t *parent);
dlist_t *push_back_list(dlist_t *li, info_t infos, dlist_node_t *parent);
dlist_t *pop_front_list(dlist_t *li);
dlist_t *clear_list(dlist_t *li);
dlist_node_t *find_node_least_f(dlist_t *li);
dlist_node_t *pop_from_open_to_close(dlist_t **open, dlist_t **close,
    dlist_node_t *to_pop, int *err);
void print_list(dlist_t *li);

/* ------------ !A_STAR ------------ */

typedef struct goal
{
    int x;
    int y;
    char **maze;
} goal_t;

typedef struct check
{
    int x;
    int y;
    int f;
} check_t;

int generate_successors(dlist_node_t *q, dlist_t **open, goal_t *goal);
void a_star(char **maze);

#endif /* !MY_H_ */
