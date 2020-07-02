/*
** EPITECH PROJECT, 2020
** solver
** File description:
** solver
*/

#include "my.h"

int my_solver(char **maze)
{
    dead_end_filling(maze);
    return (breadth_first_search(maze));
}
