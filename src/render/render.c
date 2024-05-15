#include <stdio.h>

#include "geometry/geometry.h"
#include "image.h"
#include "render.h"
#include "render/sprites.h"
#include "t_mlx.h"

#define IRRELEVANT_RETURN_VALUE 0

void render_background(t_render_input* in)
{
    for (int row = 0; row < in->game->size.h; row++)
    {
        for (int col = 0; col < in->game->size.w; col++)
        {
            if (in->game->board[row][col] == in->game->charset.WALL)
                render_image(in->mlx, &(in->sprites->wall),
                             position(col * TILE_SIZE, row * TILE_SIZE));
            else if (in->game->board[row][col] == in->game->charset.EMPTY)
                render_image(in->mlx, &(in->sprites->floor),
                             position(col * TILE_SIZE, row * TILE_SIZE));
        }
    }
}

void render_collectibles(t_render_input* in);
void render_player(t_render_input* in)
{
    t_position player = in->game->player;
    player.x *= TILE_SIZE;
    player.y *= TILE_SIZE;
    render_image(in->mlx, &(in->sprites->player), player);
}

int render(t_render_input* params)
{
    if (!params->needs_refresh)
        return IRRELEVANT_RETURN_VALUE;
    render_background(params);
    render_player(params);
    params->needs_refresh = false;
    return IRRELEVANT_RETURN_VALUE;
}

void render_image(t_mlx* mlx, const t_image* image, t_position position)
{
    mlx_put_image_to_window(mlx->mlx, mlx->window, image->img, position.x,
                            position.y);
}
