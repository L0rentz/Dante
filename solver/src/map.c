/*
** EPITECH PROJECT, 2020
** generator
** File description:
** map
*/

#include "my.h"

char **copy_file(int line, char *str, int fd)
{
    char **maze = malloc(sizeof(char *) * line);

    for (int i = 0; str != NULL && i != line - 1; i++) {
        maze[i] = strdup(str);
        free(str);
        str = get_next_line(fd);
    }
    maze[line - 1] = NULL;

    close(fd);

    return (maze);
}

char **load_file_in_mem(char *av)
{
    struct stat filestat;
    int fd = open(av, O_RDONLY);
    if (fd == -1)
        return (NULL);

    char *str = get_next_line(fd);
    if (str == NULL)
        return (NULL);

    stat(av, &filestat);
    int len = strlen(str);
    int line = filestat.st_size / len + 1;

    char **maze = copy_file(line, str, fd);

    return (maze);
}

void format_map(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {

        for (int j = 0; maze[i][j] != '\0'; j++) {

            if (maze[i][j] == ' ')
                maze[i][j] = 'o';

            else if (maze[i][j] == 'D' || maze[i][j] == 'V'
            || maze[i][j] == 'O')
                maze[i][j] = '*';
        }

    }
}

void print_map(char **map)
{
    int i = 0;
    for (; map[i + 1] != NULL; i++)
        puts(map[i]);
    printf("%s", map[i]);
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
