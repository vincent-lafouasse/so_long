#pragma once

#include "image.h"

typedef struct s_sprites {
    t_image wall;
    t_image floor;
    t_image player;
    t_image collectible;
    t_image exit;
} t_sprites;

t_sprites load_sprites(void);
