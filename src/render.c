#include <stdio.h>

#include "image.h"
#include "render.h"
#include "t_color.h"
#include "t_mlx.h"

#define IRRELEVANT_RETURN_VALUE 0

void render_image(t_mlx* mlx, t_image* image, t_position position)
{
    mlx_put_image_to_window(mlx->mlx, mlx->window, image->img, position.x,
                            position.y);
}

int render(t_render_input* params)
{
    // log_loop_event();
    if (!params->game->needs_render)
        return IRRELEVANT_RETURN_VALUE;
    /*
    put_rectangle(params->render_surface, params->game->important_rectangle,
                  RED);
    */
    render_image(params->mlx, params->render_surface, position(0, 0));
    render_image(params->mlx, params->player_sprite,
                 params->game->player_position);
    params->game->needs_render = false;
    printf("window redrawn\n");
    return IRRELEVANT_RETURN_VALUE;
}
