/*
** EPITECH PROJECT, 2020
** solver
** File description:
** breadth_first_search
*/

#include "my.h"

queue_t *check_direction(char **maze, queue_t *s_queue, int x, int y)
{
    if (maze[y][x + 1] == '*') {
        s_queue = push_back_queue(s_queue, s_queue->first, x + 1, y);
        maze[y][x + 1] = 'V';
    }

    if (maze[y + 1] != NULL && maze[y + 1][x] == '*') {
        s_queue = push_back_queue(s_queue, s_queue->first, x, y + 1);
        maze[y + 1][x] = 'V';
    }

    if (y - 1 != -1 && maze[y - 1][x] == '*') {
        s_queue = push_back_queue(s_queue, s_queue->first, x, y - 1);
        maze[y - 1][x] = 'V';
    }

    if (x - 1 != -1 && maze[y][x - 1] == '*') {
        s_queue = push_back_queue(s_queue, s_queue->first, x - 1, y);
        maze[y][x - 1] = 'V';
    }
    return (s_queue);
}

queue_t *push_new_generation(char **maze, queue_t *s_queue,
    queue_t **s_dequeue)
{
    int x = s_queue->first->x;
    int y = s_queue->first->y;

    s_queue = check_direction(maze, s_queue, x, y);

    s_queue = dequeue_front(s_queue, s_dequeue);

    return (s_queue);
}

int breadth_first_search(char **maze)
{
    queue_t *s_queue = new_queue();
    queue_t *s_dequeue = new_queue();

    s_queue = push_back_queue(s_queue, NULL, 0, 0);
    maze[0][0] = 'V';

    while (s_queue != NULL && (maze[s_queue->last->y + 1] != NULL
    || maze[s_queue->last->y][s_queue->last->x + 1] != '\0'))
        s_queue = push_new_generation(maze, s_queue, &s_dequeue);

    if (s_queue == NULL) {
        free_map(maze);
        s_dequeue = clear_queue(s_dequeue);
        return (1);
    }
    format_map(maze);
    s_queue = clear_queue(s_queue);
    s_dequeue = clear_queue(s_dequeue);
    return (0);
}