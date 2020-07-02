/*
** EPITECH PROJECT, 2020
** generator
** File description:
** main
*/

#include "my.h"

int generator(int ac, char **av)
{
    int x = ABS(atoi(av[1]));
    int y = ABS(atoi(av[2]));
    if (x == 0 || y == 0)
        return (1);

    char **maze = NULL;

    while (1) {
        maze = iterative_backtracker(x, y, ac);
        if (my_solver(maze) == 0)
            break;
    }

    print_map(maze);
    free_map(maze);
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 3)
        return (84);

    srand(time(NULL));

    if (ac == 4) {
        char tab[8] = {"perfect\0"};
        for (int i = 0; tab[i] != '\0'; i++)
            if (tab[i] != av[3][i] || strlen(av[3]) != 7)
                return (84);
    }
    if (generator(ac, av) == 1)
        return (84);

    return (0);
}