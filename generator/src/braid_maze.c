/*
** EPITECH PROJECT, 2020
** generator
** File description:
** braid_maze
*/

#include "my.h"

int open_dead_end(char **map, int x, int y)
{
    int direction = rand() % 4;
    if (direction == 0 && x - 2 >= 0 && map[y][x - 1] == 'X') {
        map[y][x - 1] = '*';
        return (1);
    }
    if (direction == 1 && map[y][x + 1] != '\0' && map[y][x + 2] != '\0'
    && map[y][x + 1] == 'X') {
        map[y][x + 1] = '*';
        return (1);
    }
    if (direction == 3 && y - 2 >= 0 && map[y - 1][x] == 'X') {
        map[y][y - 1] = '*';
        return (1);
    }
    if (direction == 4 && map[y + 1] != NULL && map[y + 2] != NULL
    && map[y + 1][x] == 'X') {
        map[y + 1][x] = '*';
        return (1);
    }
    return (0);
}

void find_dead_end(char **map, int y)
{
    for (int i = y / 2, stop = 0; map[i] != NULL; i++) {
        for (int j = 0, check = 0; map[i][j] != '\0'; j++, check = 0) {

            if (map[i][j] == 'X' || (i == 0 && j == 0)
            || (map[i + 1] == NULL && map[i][j + 1] == '\0'))
                continue;
            if (j == 0 || map[i][j - 1] == 'X')
                check += 1;
            if (map[i][j + 1] == '\0' || map[i][j + 1] == 'X')
                check += 1;
            if (i == 0 || map[i - 1][j] == 'X')
                check += 1;
            if (map[i + 1] == NULL || map[i + 1][j] == 'X')
                check += 1;
            if (check >= 3) {
                stop += open_dead_end(map, j, i);
                if (stop == 10) return;
            }
        }
    }
}

void braid_maze(char **map, int ac, int y)
{
    if (ac == 3)
        find_dead_end(map, y);
}