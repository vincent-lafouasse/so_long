#pragma once

#include <stdbool.h>
#include "geometry.h"

typedef struct
{
    char** board;
    t_dimension size;
    t_rectangle important_rectangle;
    t_position player_position;
    bool needs_render;
} t_game;
