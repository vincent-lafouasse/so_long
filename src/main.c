#include <stdio.h>

#include <X11/keysym.h>

#include "cool_ints.h"
#include "geometry.h"
#include "mlx.h"
#include "t_color.h"

#define WIDTH 600
#define HEIGHT 480
#define WINDOW_NAME ("idk, a name ig")

#define PLAYER_SPRITE_PATH "./assets/player.xpm"

#define IRRELEVANT_RETURN_VALUE 0

typedef int t_keycode;

typedef struct
{
    void* img;
    char* addr;
    int bpp;
    int line_length;
    int endian;
    t_dimension size;
} t_image;

typedef struct
{
    void* mlx;
    void* window;
} t_mlx;

void log_time(void);
void log_key_event(t_keycode);
void log_loop_event(void);

void my_mlx_pixel_put(t_image* surface, t_position px_pos, t_u32 color);
void put_rectangle(t_image* surface, t_rectangle* rect, t_u32 color);

typedef struct
{
    char** board;
    t_dimension size;
    t_rectangle important_rectangle;
} t_game;

typedef struct
{
    t_mlx* mlx;
    t_image* render_surface;
    t_image* player_sprite;
    t_game* game;
} t_render_input;

int handle_key_events(t_keycode keycode, t_mlx* mlx)
{
    log_key_event(keycode);
    if (keycode == XK_Escape)
        mlx_destroy_window(mlx->mlx, mlx->window);
    if (keycode == XK_p)
        mlx_string_put(mlx->mlx, mlx->window, 69, 420, RED,
                       "hello");
    return IRRELEVANT_RETURN_VALUE;
}

int render(t_render_input* params)
{
    // log_loop_event();
    put_rectangle(params->render_surface, &params->game->important_rectangle,
                  CORNFLOWER_BLUE);
    mlx_put_image_to_window(params->mlx->mlx,
                            params->mlx->window,
                            params->render_surface->img, 0, 0);
    return IRRELEVANT_RETURN_VALUE;
}

t_mlx init_window(t_dimension window_size, const char* window_name);

t_image init_empty_image(t_dimension size, t_mlx* mlx)
{
    t_image out;

    out.img = mlx_new_image(mlx->mlx, size.w, size.h);
    out.addr = mlx_get_data_addr(out.img, &out.bpp, &out.line_length, &out.endian);
    return out;
}

t_image load_image_xpm(const char* path, t_mlx* mlx)
{
    t_image out;
    out.img =
        mlx_xpm_file_to_image(mlx->mlx, (char*)path, &out.size.w, &out.size.h);
    out.addr = mlx_get_data_addr(out.img, &out.bpp, &out.line_length, &out.endian);
    return out;
}

int main(void)
{
    t_mlx mlx;
    mlx.mlx = mlx_init();
    mlx.window =
        mlx_new_window(mlx.mlx, WIDTH, HEIGHT, WINDOW_NAME);

    t_image player_sprite = load_image_xpm(PLAYER_SPRITE_PATH, &mlx);

    t_image render_surface = init_empty_image(dimension(WIDTH, HEIGHT), &mlx);

    t_rectangle rect = rectangle(position(5, 5), dimension(420, 69));

    t_game game = (t_game){NULL, dimension(0, 0), rect};

    t_render_input render_input =
        (t_render_input){&mlx, &render_surface, &player_sprite, &game};

    mlx_key_hook(mlx.window, handle_key_events, &mlx);
    // mlx_expose_hook(mlx.window, render, &render_input);
    mlx_loop_hook(mlx.mlx, render, &render_input);
    mlx_loop(mlx.mlx);
}

void my_mlx_pixel_put(t_image* surface, t_position px_pos, t_u32 color)
{
    char* dst = surface->addr +
                flatten_2d_position(px_pos, surface->line_length, surface->bpp);
    *(t_u32*)dst = color;
}

void put_rectangle(t_image* surface, t_rectangle* rect, t_u32 color)
{
    for (int col = 0; col < rect->size.w; col++)
    {
        for (int row = 0; row < rect->size.h; row++)
            my_mlx_pixel_put(surface,
                             position(rect->start.x + col, rect->start.y + row),
                             color);
    }
}

void log_key_event(t_keycode keycode)
{
    log_time();
    printf("\tKey Event:\t");
    switch (keycode)
    {
        case XK_Escape:
            printf("Esc");
            break;
        case XK_p:
            printf("P");
            break;
        case XK_w:
            printf("W");
            break;
        case XK_a:
            printf("A");
            break;
        case XK_s:
            printf("S");
            break;
        case XK_d:
            printf("D");
            break;
        default:
            printf("%d", keycode);
    }
    printf("\n");
}
void log_loop_event(void)
{
    log_time();
    printf("\tLoop Event\n");
}
