#pragma once

#include <stdbool.h>
#include "geometry/geometry.h"
#include "parse/t_charset.h"

typedef struct
{
    char** board;
    t_dimension size;
    t_position player;
    t_position exit;
    unsigned int n_collectibles;
    size_t move_count;
    t_charset charset;
    bool done;
} t_game;

t_game init_game(const char* map_path, t_charset charset);
void free_game(t_game* game);
