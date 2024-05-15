#pragma once

#include "game/t_game.h"
#include "image.h"
#include "sprites.h"
#include "t_mlx.h"

typedef struct
{
    t_mlx* mlx;
    const t_game* game;
    const t_sprites* sprites;
    bool needs_refresh;
} t_render_input;

int render(t_render_input* params);
void render_image(t_mlx* mlx, t_image* image, t_position position);
