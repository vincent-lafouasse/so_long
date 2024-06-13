#include "render.h"
#include "geometry/geometry.h"
#include "image.h"
#include "render/sprites.h"
#include "t_mlx.h"
#include <stdio.h>

#define IRRELEVANT_RETURN_VALUE 0

void render_collectibles(t_render_input* in)
{
    for (int row = 0; row < in->game->size.h; row++)
    {
        for (int col = 0; col < in->game->size.w; col++)
        {   if (in->game->board[row][col] == in->game->charset.COLLECTIBLE)
            render_image(in->mlx, in->sprites->collectible,
                         position_scale(position(col, row), TILE_SIZE));
        }
    }

}

void render_background(t_render_input* in)
{
    render_image(in->mlx, in->background, position(0, 0));
}

void render_player(t_render_input* in)
{
    render_image(in->mlx, in->sprites->player,
                 position_scale(in->game->player, TILE_SIZE));
}

void render_exit(t_render_input* in)
{
    render_image(in->mlx, in->sprites->exit,
                 position_scale(in->game->exit, TILE_SIZE));
}

int render(t_render_input* params)
{
    render_background(params);
        render_collectibles(params);
    if (params->game->n_collectibles == 0)
        render_exit(params);
    render_player(params);
    return IRRELEVANT_RETURN_VALUE;
}

void render_image(t_mlx* mlx, t_image image, t_position position)
{
    mlx_put_image_to_window(mlx->mlx, mlx->window, image.img, position.x,
                            position.y);
}
