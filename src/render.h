#pragma once

#include "image.h"
#include "t_game.h"
#include "t_mlx.h"

typedef struct
{
    t_mlx* mlx;
    t_image* render_surface;
    t_image* player_sprite;
    t_game* game;
} t_render_input;

int render(t_render_input* params);
void render_image(t_mlx* mlx, t_image* image, t_position position);
