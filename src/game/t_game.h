#pragma once

#include <stdbool.h>
#include "geometry/geometry.h"
#include "libft/t_list.h"
#include "parse/t_charset.h"

typedef struct
{
    char** board;
    t_dimension size;
    t_position player_position;
    t_position exit;
    t_list* collectibles;
    bool needs_render;
} t_game;

t_game init_game(const char* map_path, t_charset charset);
void free_game(t_game* game);