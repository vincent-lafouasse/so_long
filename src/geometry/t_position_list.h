#pragma once

#include "geometry.h"

#include <stddef.h>

typedef struct s_position_list
{
    t_position position;
    struct s_position_list* next;
    struct s_position_list* prev;
} t_position_list;

t_position_list* poslst_new(t_position position);
void poslst_add_front(t_position_list**, t_position_list* node);
void poslst_remove(t_position_list** poslst_ref, t_position position);
void poslst_delone(t_position_list** poslst_ref);
void poslst_clear(t_position_list** poslst_ref);
size_t poslst_size(const t_position_list* lst);
