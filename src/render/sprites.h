#pragma once

#include "image.h"

#define TILE_SIZE 64

typedef struct s_sprites
{
    t_image wall;
    t_image floor;
    t_image player;
    t_image collectible;
    t_image exit;
} t_sprites;

t_sprites load_sprites(t_mlx mlx);
