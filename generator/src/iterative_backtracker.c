/*
** EPITECH PROJECT, 2020
** generator
** File description:
** perfect_maze
*/

#include "my.h"

int check_sides(char **map, int x, int y)
{
    int check = 0;

    if (x - 1 == -1 || map[y][x - 1] == 'X')
        check++;

    if (map[y][x + 1] == '\0' || map[y][x + 1] == 'X')
        check++;

    if (y - 1 == -1 || map[y - 1][x] == 'X')
        check++;

    if (map[y + 1] == NULL || map[y + 1][x] == 'X')
        check++;

    return (check);
}

int random_direction(char **map, stack_t **s_stack, int max_x, int max_y)
{
    int x = (*s_stack)->x, y = (*s_stack)->y, direction = (rand() % 4) + 1;
    int tab[4] = {1, 2, 3, 4}, i = 0;
    for (; 1; direction = (rand() % 4) + 1) {
        for (i = 0; i != 4; i++)
            if (tab[i] == direction) tab[i] = 0;
        if (direction == 1 && x - 1 >= 0
        && map[y][x - 1] == 'X' && check_sides(map, x - 1, y) >= 3)
            return (direction);
        if (direction == 2 && x + 1 < max_x
        && map[y][x + 1] == 'X' && check_sides(map, x + 1, y) >= 3)
            return (direction);
        if (direction == 3 && y - 1 >= 0
        && map[y - 1][x] == 'X' && check_sides(map, x, y - 1) >= 3)
            return (direction);
        if (direction == 4 && y + 1 < max_y
        && map[y + 1][x] == 'X' && check_sides(map, x, y + 1) >= 3)
            return (direction);
        if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0) break;
    } (*s_stack) = pop_stack((*s_stack));
    return (0);
}

stack_t *dig_maze(char **map, stack_t *s_stack, int direction)
{
    int x = s_stack->x;
    int y = s_stack->y;

    if (direction == 1) {
        map[y][x - 1] = '*';
        s_stack = push_stack(s_stack, x - 1, y);
    }
    if (direction == 2) {
        map[y][x + 1] = '*';
        s_stack = push_stack(s_stack, x + 1, y);
    }
    if (direction == 3) {
        map[y - 1][x] = '*';
        s_stack = push_stack(s_stack, x, y - 1);
    }
    if (direction == 4) {
        map[y + 1][x] = '*';
        s_stack = push_stack(s_stack, x, y + 1);
    }
    return (s_stack);
}

void dig_loop(char **map, int *x, int *y)
{
    int direction = 0;
    stack_t *s_stack = new_stack();

    s_stack = push_stack(s_stack, 0, 0);

    while (1) {

        direction = random_direction(map, &s_stack, *x, *y);

        if (s_stack == new_stack())
            break;

        if (direction == 0)
            continue;

        s_stack = dig_maze(map, s_stack, direction);

    }
}

char **iterative_backtracker(int x, int y, int ac)
{
    char **map = create_map(x, y);

    map[0][0] = '*';

    dig_loop(map, &x, &y);
    braid_maze(map, ac, y);

    map[y - 1][x - 1] = '*';

    return (map);
}