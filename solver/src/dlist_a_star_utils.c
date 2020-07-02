/*
** EPITECH PROJECT, 2020
** solver
** File description:
** dlist_a_star_utils
*/

#include "my.h"

void pop_middle_back(dlist_t **open, dlist_t **close, dlist_node_t *to_pop,
    int *err)
{
    if (*err == 0 && to_pop == (*open)->end) {

        (*open)->end = (*open)->end->back;
        (*open)->end->next = NULL;
        to_pop->back = (*close)->end;
        (*close)->end->next = to_pop;
        (*close)->end = to_pop;
        *err += 1;
        return;
    }

    if (*err == 0) {

        to_pop->next->back = to_pop->back;
        to_pop->back->next = to_pop->next;
        to_pop->next = NULL;
        to_pop->back = (*close)->end;
        (*close)->end->next = to_pop;
        (*close)->end = to_pop;
    }
}

void pop_front(dlist_t **open, dlist_t **close, dlist_node_t *to_pop, int *err)
{
    if ((*open)->begin == (*open)->end) {
        free ((*open));
        to_pop->back = (*close)->end;
        (*close)->end->next = to_pop;
        (*close)->end = to_pop;
        *err += 100;
        return;
    }

    if (*err == 0 && to_pop == (*open)->begin) {

        (*open)->begin = (*open)->begin->next;
        (*open)->begin->back = NULL;
        to_pop->next = NULL;
        to_pop->back = (*close)->end;
        (*close)->end->next = to_pop;
        (*close)->end = to_pop;
        *err += 1;
    }
}

dlist_node_t *pop_from_open_to_close(dlist_t **open, dlist_t **close,
    dlist_node_t *to_pop, int *err)
{
    if (is_empty_list((*open)))
        return (NULL);

    if (is_empty_list((*close))) {
        (*close) = malloc(sizeof(dlist_t));
        (*close)->length = 0;
        (*open)->begin = (*open)->begin->next;
        (*open)->begin->back = NULL;
        to_pop->next = NULL;
        to_pop->back = NULL;
        (*close)->begin = to_pop;
        (*close)->end = to_pop;
        return ((*close)->end);
    }

    pop_front(open, close, to_pop, err);
    if (*err == 0) pop_middle_back(open, close, to_pop, err);
    return ((*close)->end);
}

dlist_node_t *find_node_least_f(dlist_t *li)
{
    int f = INT_MAX;
    dlist_node_t *tmp = li->begin;
    dlist_node_t *found = NULL;

    while (tmp != NULL) {

        if (tmp->info.f < f) {
            f = tmp->info.f;
            found = tmp;
        }

        tmp = tmp->next;

    }

    return (found);
}

dlist_t *clear_list(dlist_t *li)
{
    while (!is_empty_list(li))
        li = pop_front_list(li);

    return (new_list());
}