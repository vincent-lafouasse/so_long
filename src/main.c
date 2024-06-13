#include <X11/X.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "game/t_game.h"
#include "game/update_game.h"
#include "geometry/geometry.h"
#include "mlx.h"
#include "parse/t_charset.h"

#include "render/background.h"
#include "render/render.h"

#include "error/error.h"
#include "log/log.h"

#define IRRELEVANT_RETURN_VALUE 0

t_render_input build_render_input(t_mlx* mlx, const t_game* game, const t_sprites* sprites, size_t tile_size)
{
    t_render_input render_input;
    render_input.mlx = mlx;
    render_input.game = game;
    render_input.sprites = sprites;
    render_input.needs_refresh = true;
    render_input.background = make_background(game, sprites, mlx, tile_size);

    return render_input;
}

int exit_hook(t_mlx* mlx);
int key_hook(t_keycode keycode, t_update_input* input);
int loop_hook(t_render_input* params);
void cleanup(t_mlx mlx);

int main(int ac, char** av)
{
    if (ac != 2)
        die("Usage: ./so_long map.ber");

    t_game game = init_game(av[1], default_charset());

    t_mlx mlx = init_mlx(dimension_scale(game.size, TILE_SIZE), "a cool game");

    t_sprites sprites = load_sprites(mlx);

    t_render_input render_input = build_render_input(&mlx, &game, &sprites, TILE_SIZE);
    t_update_input update_input = (t_update_input){
        &game, &mlx, .needs_refresh = &render_input.needs_refresh};

    mlx_hook(mlx.window, DestroyNotify, StructureNotifyMask, exit_hook, &mlx);
    mlx_key_hook(mlx.window, &key_hook, &update_input);
    mlx_loop_hook(mlx.mlx, &loop_hook, &render_input);
    mlx_loop(mlx.mlx);

    cleanup(mlx);
    free_game(&game);
}

int key_hook(t_keycode keycode, t_update_input* input)
{
    if (keycode == XK_Escape)
        exit_hook(input->mlx);
    update_game(input->game, keycode);
    *(input->needs_refresh) = true;
    return IRRELEVANT_RETURN_VALUE;
}

int loop_hook(t_render_input* params)
{
    if (params->game->done)
    {
        printf("gg my guy\n");
        exit_hook(params->mlx);
    }
    if (params->needs_refresh == false)
        return IRRELEVANT_RETURN_VALUE;
    render(params);
    params->needs_refresh = false;
    return IRRELEVANT_RETURN_VALUE;
}

int exit_hook(t_mlx* mlx)
{
    mlx_loop_end(mlx->mlx);
    return IRRELEVANT_RETURN_VALUE;
}

void cleanup(t_mlx mlx)
{
    // will cleanup sprites too, later tho
    // free_sprites(sprites) or something
    mlx_destroy_window(mlx.mlx, mlx.window);
    mlx_destroy_display(mlx.mlx);
    free(mlx.mlx);
}
