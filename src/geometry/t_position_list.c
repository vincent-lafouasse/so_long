#include "t_position_list.h"

#include <stdlib.h>
#include "geometry.h"

static t_position_node* posnode_new(t_position position);

void poslst_remove(t_position_list* lst, t_position position)
{
    if (!lst)
        return;
    while (lst->head && position_eq(position, lst->head->position))
        poslst_delone(lst);
    if (lst->head == NULL || lst->head->next == NULL)
        return;

    t_position_node* current = lst->head;
    t_position_node* new_next;
    while (current->next)
    {
        if (position_eq(position, current->next->position))
        {
            new_next = current->next->next;
            free(current->next);
            current->next = new_next;
            new_next->prev = current;
        }
        else
            current = current->next;
    }
}

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

void poslst_delone(t_position_list* lst)
{
    t_position_node* new_head;
    if (!lst || !lst->head)
        return;
    if (lst->head->next == NULL)
    {
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
        return;
    }
    new_head = lst->head->next;
    free(lst->head);
    lst->head = new_head;
    new_head->prev = NULL;
}

void poslst_clear(t_position_list* lst)
{
    if (!lst)
        return;
    while (lst->head)
        poslst_delone(lst);
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

void posnode_erase(t_position_node* node)
{
    if (!node)
        return;
    t_position_node* next = node->next;
    t_position_node* prev = node->prev;
    free(node);
    next->prev = prev;
    prev->next = next;
}
