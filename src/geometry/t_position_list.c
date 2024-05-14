#include "t_position_list.h"

#include <stdlib.h>
#include "geometry.h"

static t_position_node* posnode_new(t_position position);

t_position_list poslst_new(void)
{
    return (t_position_list){.head = NULL, .tail = NULL};
}

size_t poslst_size(t_position_list lst)
{
    t_position_node* current = lst.head;
    size_t size = 0;

    while (current)
    {
        current = current->next;
        size++;
    }
    return size;
}

bool poslst_add_front(t_position_list* lst, t_position position)
{
    t_position_node* new_head;

    if (!lst)
        return false;
    new_head = posnode_new(position);
    if (new_head == NULL)
        return false;
    if (lst->head == NULL)
    {
        lst->head = new_head;
        lst->tail = new_head;
        return true;
    }
    new_head->next = lst->head;
    lst->head->prev = new_head;
    lst->head = new_head;
    return true;
}


static t_position_node* posnode_new(t_position position)
{
    t_position_node* out;

    out = malloc(sizeof(*out));
    if (!out)
        return NULL;

    out->position = position;
    out->next = NULL;
    out->prev = NULL;

    return out;
}

/*
void poslst_delone(t_position_list** poslst_ref)
{
    t_position_list* new_head;

    if (!poslst_ref || !*poslst_ref)
        return;
    new_head = (*poslst_ref)->next;
    free(*poslst_ref);
    *poslst_ref = new_head;
}

void poslst_add_front(t_position_list** poslst_ref, t_position_list* node)
{
    t_position_list* memory;

    if (!poslst_ref)
        return;

    if (!*poslst_ref)
    {
        *poslst_ref = node;
        return;
    }
    memory = *poslst_ref;
    *poslst_ref = node;
    node->next = memory;
    node->next->prev = node;
}

void poslst_remove(t_position_list** poslst_ref, t_position position)
{
    if (!poslst_ref)
        return;

    while (*poslst_ref && position_eq(position, (*poslst_ref)->position))
        poslst_delone(poslst_ref);

    if (!*poslst_ref || (*poslst_ref)->next == NULL)
        return;

    t_position_list* previous = *poslst_ref;
    t_position_list* current = previous->next;

    while (current)
    {
        if (position_eq(position, (*poslst_ref)->position))
        {
            previous->next = current->next;
            free(current);
            current = previous->next;
            continue;
        }
        previous = current;
        current = current->next;
    }
}

void poslst_clear(t_position_list** poslst_ref)
{
    if (!poslst_ref)
        return;

    while (*poslst_ref)
    {
        poslst_delone(poslst_ref);
    }
}

size_t poslst_size(const t_position_list* lst)
{
    size_t sz = 0;

    while (lst)
    {
        sz++;
        lst = lst->next;
    }

    return sz;
}
*/
