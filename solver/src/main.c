/*
** EPITECH PROJECT, 2020
** solver
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);

    char **maze = load_file_in_mem(av[1]);
    if (maze == NULL)
        return (84);

    dead_end_filling(maze);
    breadth_first_search(maze);

    free_map(maze);

    return (0);
}
