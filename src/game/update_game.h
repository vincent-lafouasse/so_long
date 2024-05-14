#pragma once

#include "render/t_mlx.h"
#include "t_game.h"

typedef struct
{
    t_game* game;
    t_mlx* mlx;
} t_update_input;

int update_game(t_keycode keycode, t_update_input* input);