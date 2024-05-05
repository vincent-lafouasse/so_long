#include <stdio.h>

#include "geometry/geometry.h"
#include "image.h"
#include "render.h"
#include "t_mlx.h"

#define IRRELEVANT_RETURN_VALUE 0

void render_image(t_mlx* mlx, t_image* image, t_position position)
{
    mlx_put_image_to_window(mlx->mlx, mlx->window, image->img, position.x,
                            position.y);
}

void ascii_render(const t_game* game);

int render(t_render_input* params)
{
    if (!params->game->needs_render)
        return IRRELEVANT_RETURN_VALUE;
    printf("redrawing\n");
    ascii_render(params->game);
    params->game->needs_render = false;
    printf("window redrawn\n");
    return IRRELEVANT_RETURN_VALUE;
}

bool is_wall(t_position position, const t_game* game);
bool is_player(t_position position, const t_game* game);
bool is_exit(t_position position, const t_game* game);
bool is_collectible(t_position position, const t_game* game);

void ascii_render(const t_game* game)
{
    for (int row = 0; row < game->size.h; row++)
    {
        for (int col = 0; col < game->size.w; col++)
        {
            t_position current = position(col, row);
            if (is_wall(current, game))
                printf("#");
            else if (is_player(current, game) && game->collectibles)
                printf("x");
            else if (is_player(current, game) && !game->collectibles)
                printf("X");
            else if (is_exit(current, game) && game->collectibles)
                printf(" ");
            else if (is_exit(current, game) && !game->collectibles)
                printf("_");
            else if (is_collectible(current, game))
                printf("o");
            else
                printf(" ");
        }
        printf("\n");
    }
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
    return true;
}

bool is_wall(t_position position, const t_game* game)
{
    return game->board[position.y][position.x] == game->charset.WALL;
}
