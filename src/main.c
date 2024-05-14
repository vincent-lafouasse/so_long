#include <X11/X.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "game/t_game.h"
#include "game/update_game.h"
#include "geometry/t_position_list.h"
#include "mlx.h"
#include "parse/t_charset.h"

#include "render/render.h"

#include "error/error.h"
#include "log/log.h"

#define WIDTH 600
#define HEIGHT 480
#define WINDOW_NAME ("idk, a name ig")
#define IRRELEVANT_RETURN_VALUE 0

int exit_hook(t_mlx* mlx);
int key_hook(t_keycode keycode, t_update_input* input);
void cleanup(t_mlx mlx);

int main(int ac, char** av)
{
    if (ac != 2)
        die("Usage: ./so_long map.ber");

    t_game game = init_game(av[1], default_charset());
    log_game(game);

    const t_dimension window_size =
        dimension(game.size.w * TILE_SIZE, game.size.h * TILE_SIZE);
    t_mlx mlx = init_mlx(window_size, WINDOW_NAME);

    t_sprites sprites = load_sprites(mlx);

    t_update_input update_input = (t_update_input){&game, &mlx};
    t_render_input render_input = (t_render_input){&mlx, &game, &sprites};

    mlx_hook(mlx.window, DestroyNotify, StructureNotifyMask, exit_hook, &mlx);
    mlx_key_hook(mlx.window, &key_hook, &update_input);
    mlx_loop_hook(mlx.mlx, &render, &render_input);
    mlx_loop(mlx.mlx);

    cleanup(mlx);
    free_game(&game);
}

int key_hook(t_keycode keycode, t_update_input* input)
{
    if (keycode == XK_Escape)
        exit_hook(input->mlx);
    update_game(input->game, keycode);
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
