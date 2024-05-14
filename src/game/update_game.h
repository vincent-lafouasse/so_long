#pragma once

#include "render/t_mlx.h"
#include "t_game.h"

typedef struct
{
    t_game* game;
    t_mlx* mlx;
} t_update_input;

void update_game(t_game* game, int keycode);
