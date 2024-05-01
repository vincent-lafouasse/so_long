#pragma once

#include "geometry.h"

typedef struct s_position_list
{
    t_position position;
    struct s_position_list* next;
} t_position_list;

t_position_list* poslst_new(t_position position);
void poslst_add_front(t_position_list**, t_position_list* node);
void poslst_remove(t_position_list** poslst_ref, t_position position);
void poslst_clear(t_position_list** poslst_ref);
