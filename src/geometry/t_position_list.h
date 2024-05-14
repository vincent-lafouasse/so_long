#pragma once

#include "geometry.h"

#include <stddef.h>

typedef struct s_position_node
{
    t_position position;
    struct s_position_node* next;
    struct s_position_node* prev;
} t_position_node;

typedef struct s_position_list
{
    t_position_node* head;
    t_position_node* tail;
} t_position_list;

t_position_list poslst_new(void);
size_t poslst_size(t_position_list lst);
bool poslst_add_front(t_position_list* lst, t_position position);
void poslst_delone(t_position_list* lst);
void poslst_clear(t_position_list* lst);
void posnode_erase(t_position_node* node);
void poslst_remove(t_position_list* lst, t_position position);
