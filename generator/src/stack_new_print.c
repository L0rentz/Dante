/*
** EPITECH PROJECT, 2020
** generator
** File description:
** stack_utils
*/

#include "my.h"

stack_t *new_stack(void)
{
    return (NULL);
}

int is_empty_stack(stack_t *s_stack)
{
    if (s_stack == NULL)
        return (1);
    return (0);
}

void print_stack(stack_t *s_stack)
{
    stack_t *tmp = s_stack;

    while (tmp != NULL) {
        printf("X = %d ", tmp->x);
        printf("Y = %d\n", tmp->y);
        tmp = tmp->down;
    }
}