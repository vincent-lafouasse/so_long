#pragma once

#include "t_position_list.h"

typedef struct s_position_deque
{
    t_position_list* head;
    t_position_list* tail;
} t_position_deque;
