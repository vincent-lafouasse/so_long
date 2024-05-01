#include "t_position_list.h"

#include <stdlib.h>
#include "geometry/geometry.h"

static void poslst_delone(t_position_list** poslst_ref)
{
    t_position_list* new_head;

    if (!poslst_ref || !*poslst_ref)
        return;
    new_head = (*poslst_ref)->next;
    free(*poslst_ref);
    *poslst_ref = new_head;
}

t_position_list* poslst_new(t_position position)
{
    t_position_list* out;

    out = malloc(sizeof(*out));
    if (!out)
        return NULL;

    out->position = position;
    out->next = NULL;

    return out;
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
}

void poslst_remove(t_position_list** poslst_ref, t_position position)
{

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
