#include <stdio.h>

#include "geometry/geometry.h"
#include "image.h"
#include "render.h"
#include "t_mlx.h"

#define IRRELEVANT_RETURN_VALUE 0

bool is_wall(t_position position, const t_game* game);
bool is_player(t_position position, const t_game* game);
bool is_exit(t_position position, const t_game* game);
bool is_collectible(t_position position, const t_game* game);

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

int render(t_render_input* params)
{
    if (!params->game->needs_render)
        return IRRELEVANT_RETURN_VALUE;
    render_background(params);
    params->game->needs_render = false;
    return IRRELEVANT_RETURN_VALUE;
}

bool is_player(t_position position, const t_game* game)
{
    return position_compare(position, game->player) == 0;
}
bool is_exit(t_position position, const t_game* game)
{
    return position_compare(position, game->exit) == 0;
}
bool is_collectible(t_position position, const t_game* game)
{
    const t_position_list* collectibles = game->collectibles;
    while (collectibles)
    {
        if (position_compare(position, collectibles->position) == 0)
            return true;
        collectibles = collectibles->next;
    }
    return false;
}

bool is_wall(t_position position, const t_game* game)
{
    return game->board[position.y][position.x] == game->charset.WALL;
}

void render_image(t_mlx* mlx, t_image* image, t_position position)
{
    mlx_put_image_to_window(mlx->mlx, mlx->window, image->img, position.x,
                            position.y);
}
