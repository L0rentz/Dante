/*
** EPITECH PROJECT, 2020
** solver
** File description:
** dlist
*/

#include "my.h"

dlist_t *new_list(void)
{
    return (NULL);
}

int is_empty_list(dlist_t *li)
{
    if (li == NULL)
        return (1);

    return (0);
}

dlist_node_t *new_dlist_node(info_t infos, dlist_node_t *parent)
{
    dlist_node_t *element;

    element = malloc(sizeof(*element));
    element->info = infos;
    element->parent = parent;
    element->next = NULL;
    element->back = NULL;

    return (element);
}

dlist_t *push_back_list(dlist_t *li, info_t infos, dlist_node_t *parent)
{
    dlist_node_t *element = new_dlist_node(infos, parent);

    if (is_empty_list(li)) {
        li = malloc(sizeof(*li));
        li->length = 0;
        li->begin = element;
        li->end = element;
    }

    else {
        li->end->next = element;
        element->back = li->end;
        li->end = element;
    }

    li->length++;

    return (li);
}

dlist_t *pop_front_list(dlist_t *li)
{
    if (is_empty_list(li))
        return (new_list());

    if (li->begin == li->end) {
        free(li->begin);
        free (li);
        return (new_list());
    }

    dlist_node_t *tmp = li->begin;

    li->begin = li->begin->next;
    li->begin->back = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    free (tmp);

    li->length--;

    return (li);
}