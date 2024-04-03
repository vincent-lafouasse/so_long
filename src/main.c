#include <stdbool.h>
#include <stdio.h>

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

int update_game(t_keycode keycode, t_update_input* input)
{
    log_key_event(keycode);
    if (keycode == XK_Escape)
        mlx_destroy_window(input->mlx->mlx, input->mlx->window);
    if (keycode == XK_p)
        mlx_string_put(input->mlx->mlx, input->mlx->window, 69, 420, RED,
                       "hello");
    if (keycode == XK_s)
        input->game->player_position.y += 32;
    input->game->needs_render = true;
    return IRRELEVANT_RETURN_VALUE;
}

t_mlx init_mlx(t_dimension window_size, const char* window_name);

int main(void)
{
    const t_dimension window_size = dimension(WIDTH, HEIGHT);
    t_mlx mlx = init_mlx(window_size, WINDOW_NAME);
    t_image player_sprite = load_image_xpm(PLAYER_SPRITE_PATH, &mlx);

    t_image background = init_empty_image(window_size, &mlx);
    put_rectangle(&background, rectangle(position(0, 0), window_size),
                  CORNFLOWER_BLUE);

    t_rectangle rect = rectangle(position(5, 5), dimension(420, 69));

    t_game game = (t_game){NULL, dimension(0, 0), rect, position(69, 42), true};

    t_update_input update_input = (t_update_input){&game, &mlx};
    t_render_input render_input =
        (t_render_input){&mlx, &background, &player_sprite, &game};

    mlx_key_hook(mlx.window, update_game, &update_input);
    // mlx_expose_hook(mlx.window, render, &render_input);
    mlx_loop_hook(mlx.mlx, &render, &render_input);
    mlx_loop(mlx.mlx);
}

void my_mlx_pixel_put(t_image* surface, t_position px_pos, t_u32 color)
{
    char* dst = surface->addr +
                flatten_2d_position(px_pos, surface->line_length, surface->bpp);
    *(t_u32*)dst = color;
}

void put_rectangle(t_image* surface, t_rectangle rect, t_u32 color)
{
    for (int col = 0; col < rect.size.w; col++)
    {
        for (int row = 0; row < rect.size.h; row++)
            my_mlx_pixel_put(surface,
                             position(rect.start.x + col, rect.start.y + row),
                             color);
    }
}
t_mlx init_mlx(t_dimension window_size, const char* window_name)
{
    t_mlx mlx;
    mlx.mlx = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx, window_size.w, window_size.h,
                                (char*)window_name);
    return mlx;
}

t_image init_empty_image(t_dimension size, t_mlx* mlx)
{
    t_image out;

    out.img = mlx_new_image(mlx->mlx, size.w, size.h);
    out.addr =
        mlx_get_data_addr(out.img, &out.bpp, &out.line_length, &out.endian);
    return out;
}

t_image load_image_xpm(const char* path, t_mlx* mlx)
{
    t_image out;
    out.img =
        mlx_xpm_file_to_image(mlx->mlx, (char*)path, &out.size.w, &out.size.h);
    out.addr =
        mlx_get_data_addr(out.img, &out.bpp, &out.line_length, &out.endian);
    return out;
}
