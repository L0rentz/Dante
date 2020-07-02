/*
** EPITECH PROJECT, 2020
** solver
** File description:
** a_star
*/

#include "my.h"

goal_t find_goal_pos(char **maze)
{
    goal_t goal = {0, 0, maze};

    while (maze[goal.y + 1] != NULL)
        goal.y++;

    while (maze[goal.y][goal.x + 1] != '\0')
        goal.x++;

    return (goal);
}

int a_star_loop(char **maze, dlist_node_t **q, dlist_t **s_open,
    dlist_t **s_close)
{
    (*s_open) = push_back_list((*s_open), (info_t){0, 0, 0, 0, 0}, NULL);

    goal_t goal = find_goal_pos(maze);
    int err = 0;

    while ((*s_open) != NULL) {

        err = 0;

        (*q) = find_node_least_f((*s_open));
        if (generate_successors((*q), s_open, &goal))
            break;
        (*q) = pop_from_open_to_close(s_open, s_close, (*q), &err);

        if (err >= 100)
            return (1);

    }
    return (0);
}

void a_star(char **maze)
{
    dlist_t *s_open = new_list();
    dlist_t *s_close = new_list();
    dlist_node_t *q = NULL;

    int err = a_star_loop(maze, &q, &s_open, &s_close);

    if (err == 0) {
        dlist_node_t *tmp = q;

        while (tmp != NULL) {
            maze[tmp->info.y][tmp->info.x] = ' ';
            tmp = tmp->parent;
        }
        format_map(maze);
        print_map(maze);
        clear_list(s_open);
    }
    else
        puts("no solution found");
    clear_list(s_close);
}