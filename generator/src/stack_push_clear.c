/*
** EPITECH PROJECT, 2020
** generator
** File description:
** stack_push_clear
*/

#include "my.h"

stack_t *push_stack(stack_t *s_stack, int x, int y)
{
    stack_t *new = malloc(sizeof(stack_t));

    if (is_empty_stack(s_stack)) {
        new->x = x;
        new->y = y;
        new->down = NULL;
    }

    else {
        new->x = x;
        new->y = y;
        new->down = s_stack;
    }

    return (new);
}

stack_t *pop_stack(stack_t *s_stack)
{
    if (is_empty_stack(s_stack))
        return (new_stack());

    stack_t *tmp = s_stack->down;

    free(s_stack);
    s_stack = NULL;

    return (tmp);
}

stack_t *clear_stack(stack_t *s_stack)
{
    while (s_stack != NULL)
        s_stack = pop_stack(s_stack);

    return (new_stack());
}