#pragma once

#include "game/t_game.h"
#include "image.h"
#include "sprites.h"
#include "hooks/hooks.h"
#include "t_mlx.h"

int render(t_render_input* params);
void render_image(t_mlx* mlx, t_image image, t_position position);
