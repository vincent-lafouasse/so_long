#pragma once

#include <stdbool.h>
#include "geometry/geometry.h"
#include "geometry/t_position_list.h"
#include "parse/t_charset.h"

typedef struct
{
    char** board;
    t_dimension size;
    t_position player;
    t_position exit;
    t_position_list collectibles;
    t_charset charset;
    bool needs_render;
    bool done;
} t_game;

t_game init_game(const char* map_path, t_charset charset);
void free_game(t_game* game);
