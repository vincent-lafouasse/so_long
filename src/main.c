#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <X11/keysym.h>

#include "image.h"
#include "log.h"
#include "mlx.h"
#include "render.h"
#include "t_color.h"
#include "t_game.h"
#include "t_mlx.h"

#define WIDTH 600
#define HEIGHT 480
#define WINDOW_NAME ("idk, a name ig")

#define PLAYER_SPRITE_PATH "./assets/player.xpm"

#define IRRELEVANT_RETURN_VALUE 0

typedef struct
{
    t_game* game;
    t_mlx* mlx;
} t_update_input;

void ft_quit(t_mlx* mlx)
{
    //mlx_destroy_window(mlx->mlx, mlx->window);
    //mlx_loop_end(mlx->mlx);
    exit(0);
}

int update_game(t_keycode keycode, t_update_input* input)
{
    log_key_event(keycode);
    if (keycode == XK_Escape)
    {
        ft_quit(input->mlx);
    }
    if (keycode == XK_p)
        mlx_string_put(input->mlx->mlx, input->mlx->window, 69, 420, RED,
                       "hello");
    if (keycode == XK_s)
        input->game->player_position.y += 32;
    input->game->needs_render = true;
    return IRRELEVANT_RETURN_VALUE;
}

int main(void)
{
    const t_dimension window_size = dimension(WIDTH, HEIGHT);
    t_mlx mlx = init_mlx(window_size, WINDOW_NAME);
    t_image player_sprite = load_image_xpm(PLAYER_SPRITE_PATH, &mlx);

    t_image background = init_empty_image(window_size, &mlx);
    put_rectangle(&background, rectangle(position(0, 0), window_size),
                  BLACK);

    t_rectangle rect = rectangle(position(5, 5), dimension(420, 69));

    t_game game = (t_game){NULL, dimension(0, 0), rect, position(69, 42), true};

    t_update_input update_input = (t_update_input){&game, &mlx};
    t_render_input render_input =
        (t_render_input){&mlx, &background, &player_sprite, &game};

    mlx_key_hook(mlx.window, &update_game, &update_input);
    // mlx_expose_hook(mlx.window, render, &render_input);
    mlx_loop_hook(mlx.mlx, &render, &render_input);
    mlx_loop(mlx.mlx);
}
