/*
** EPITECH PROJECT, 2020
** solver
** File description:
** successors
*/

#include "my.h"

void successor_1(dlist_node_t *q, dlist_t **open, goal_t *goal)
{

    if (goal->maze[q->info.y][q->info.x + 1] == '*') {

        int g = ABS((q->info.y - q->info.y) + (q->info.x - (q->info.x + 1)));
        int h = ABS((q->info.x + 1) - goal->x + (q->info.y - goal->y));
        int f = g + h;

        (*open) = push_back_list((*open), (info_t){g, h, f, q->info.x + 1,
            q->info.y}, q);

        goal->maze[q->info.y][q->info.x + 1] = 'V';

    }

}

void successor_2(dlist_node_t *q, dlist_t **open, goal_t *goal)
{

    if (q->info.x - 1 != -1 && goal->maze[q->info.y][q->info.x - 1] == '*') {

        int g = ABS((q->info.y - q->info.y) + (q->info.x - (q->info.x - 1)));
        int h = ABS((q->info.x - 1) - goal->x + (q->info.y - goal->y));
        int f = g + h;

        (*open) = push_back_list((*open), (info_t){g, h, f, q->info.x - 1,
            q->info.y}, q);

        goal->maze[q->info.y][q->info.x - 1] = 'V';

    }

}

void successor_3(dlist_node_t *q, dlist_t **open, goal_t *goal)
{

    if (goal->maze[q->info.y + 1] != NULL
    && goal->maze[q->info.y + 1][q->info.x] == '*') {

        int g = ABS((q->info.y - (q->info.y + 1)) + (q->info.x - q->info.x));
        int h = ABS(q->info.x - goal->x + ((q->info.y + 1) - goal->y));
        int f = g + h;

        (*open) = push_back_list((*open), (info_t){g, h, f, q->info.x,
            q->info.y + 1}, q);

        goal->maze[q->info.y + 1][q->info.x] = 'V';

    }

}

void successor_4(dlist_node_t *q, dlist_t **open, goal_t *goal)
{
    if (q->info.y - 1 != -1 && goal->maze[q->info.y - 1][q->info.x] == '*') {

        int g = ABS((q->info.y - (q->info.y - 1)) + (q->info.x - q->info.x));
        int h = ABS(q->info.x - goal->x + ((q->info.y - 1) - goal->y));
        int f = g + h;

        (*open) = push_back_list((*open), (info_t){g, h, f, q->info.x,
            q->info.y - 1}, q);

        goal->maze[q->info.y - 1][q->info.x] = 'V';

    }

}

int generate_successors(dlist_node_t *q, dlist_t **open, goal_t *goal)
{

    if (q->info.x == goal->x && q->info.y == goal->y)
        return (1);

    successor_1(q, open, goal);
    successor_2(q, open, goal);
    successor_3(q, open, goal);
    successor_4(q, open, goal);

    return (0);

}