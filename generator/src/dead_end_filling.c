/*
** EPITECH PROJECT, 2020
** solver
** File description:
** dead_end_filling
*/

#include "my.h"

void check_junction(char **maze, int x, int y, int *check)
{
    if (x != 0 && maze[y][x - 1] == '*')
        *check += 1;

    if (maze[y][x + 1] != '\0' && maze[y][x + 1] == '*')
        *check += 1;

    if (y != 0 && maze[y - 1][x] == '*')
        *check += 1;

    if (maze[y + 1] != NULL && maze[y + 1][x] == '*')
        *check += 1;
}

void fill_conditions(char **maze, int *x, int *y)
{
    if (*x != 0 && maze[*y][*x - 1] == '*') {
        maze[*y][*x] = 'D';
        *x -= 1;
        return;
    }
    if (maze[*y][*x + 1] != '\0' && maze[*y][*x + 1] == '*') {
        maze[*y][*x] = 'D';
        *x += 1;
        return;
    }
    if (*y != 0 && maze[*y - 1][*x] == '*') {
        maze[*y][*x] = 'D';
        *y -= 1;
        return;
    }
    if (maze[*y + 1] != NULL && maze[*y + 1][*x] == '*') {
        maze[*y][*x] = 'D';
        *y += 1;
    }
}

void fill_dead_end(char **maze, int x, int y)
{
    int check = 0;

    check_junction(maze, x, y, &check);

    while (check == 1) {
        check = 0;

        if ((x == 0 && y == 0)
        || (maze[y + 1] == NULL && maze[y][x + 1] == '\0'))
            break;

        fill_conditions(maze, &x, &y);
        check_junction(maze, x, y, &check);
    }
}

void dead_end_filling(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {
        for (int j = 0, check = 0; maze[i][j] != '\0'; j++, check = 0) {

            if (maze[i][j] == 'X' || (i == 0 && j == 0)
            || (maze[i + 1] == NULL && maze[i][j + 1] == '\0'))
                continue;

            if (j == 0 || maze[i][j - 1] == 'X')
                check += 1;
            if (maze[i][j + 1] == '\0' || maze[i][j + 1] == 'X')
                check += 1;
            if (i == 0 || maze[i - 1][j] == 'X')
                check += 1;
            if (maze[i + 1] == NULL || maze[i + 1][j] == 'X')
                check += 1;

            if (check >= 3)
                fill_dead_end(maze, j, i);
        }
    }
}