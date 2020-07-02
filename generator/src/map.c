/*
** EPITECH PROJECT, 2020
** generator
** File description:
** map
*/

#include "my.h"

void format_map(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {

        for (int j = 0; maze[i][j] != '\0'; j++) {
            if (maze[i][j] == 'D' || maze[i][j] == 'V'
            || maze[i][j] == 'O')
                maze[i][j] = '*';
        }

    }
}

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {

        if (map[i + 1] != NULL)
            puts(map[i]);

        else
            printf("%s", map[i]);

    }
}

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
        map[i] = NULL;
    }

    free(map);
    map = NULL;
}

char **create_map(int x, int y)
{
    char **map = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i != y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        memset(map[i], 'X', x);
        map[i][x] = '\0';
    }
    map[y] = NULL;

    return (map);
}

void format_exit(char **map, int x, int y)
{
    if (x - 2 > -1 && map[y - 1][x - 2] == 'X'
    && y - 2 > -1 && map[y - 2][x - 1] == 'X')
        map[y - 1][x - 2] = '*';
    map[y - 1][x - 1] = '*';

    if (x - 3 > -1 && y - 3 > -1 && map[y - 1][x - 1] == '*'
    && map[y - 2][x - 1] == '*' && map[y - 1][x - 2] == '*'
    && map[y - 2][x - 2] == '*') {
        if (map[y - 1][x - 3] == 'X')
            map[y - 1][x - 2] = 'X';
        else
            map[y - 2][x - 1] = 'X';
    }
}