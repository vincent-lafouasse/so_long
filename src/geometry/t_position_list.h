#pragma once

#include "geometry.h"

typedef struct s_position_list
{
    t_position position;
    struct s_position_list* next;
    struct s_position_list* prev;
} t_position_list;

t_position_list* poslst_new(t_position position);
void poslst_add_front(t_position_list**, t_position_list* node);
bool poslst_emplace_front(t_position_list** poslst_ref, t_position pos);
t_position poslst_pop_back(t_position_list**);
void poslst_remove(t_position_list** poslst_ref, t_position position);
void poslst_delone(t_position_list** poslst_ref);
void poslst_clear(t_position_list** poslst_ref);
