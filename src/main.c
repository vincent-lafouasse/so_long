#include <stdio.h>
#include <stdint.h>
#include <X11/keysym.h>
#include "mlx.h"
#include "geometry.h"
#include "cool_ints.h"
#include "t_color.h"

#define WIDTH 600
#define HEIGHT 480
#define WINDOW_NAME ("idk, a name ig")

#define IRRELEVANT_RETURN_VALUE 0

typedef int t_keycode;

typedef struct {
    void* img;
    char* addr;
    int bpp;
    int line_length;
    int endian;
} t_surface;

void my_mlx_pixel_put(t_surface* surface, t_position px_pos,  t_u32 color)
{
    char* dst = surface->addr + flatten_2d_position(px_pos, surface->line_length, surface->bpp);
    *(t_u32*)dst = color;
}

void put_rectangle(t_surface* surface, t_rectangle* rect, t_u32 color)
{
    for (int col = 0; col < rect->size.w; col++)
    {
        for (int row = 0; row < rect->size.h; row++)
            my_mlx_pixel_put(surface, position(rect->start.x + col, rect->start.y + row),color);
    }
}

typedef struct {
    void* mlx;
    void* window;
} t_mlx_objects;

int handle_key_events(t_keycode keycode, t_mlx_objects* mlx_objects)
{
    printf("Key Event: received key event with keycode %x\n", keycode);
    if (keycode == XK_Escape)
        mlx_destroy_window(mlx_objects->mlx, mlx_objects->window);
    if (keycode == XK_p)
        mlx_string_put(mlx_objects->mlx, mlx_objects->window, 69, 420, RED, "hello");
    return IRRELEVANT_RETURN_VALUE;
}

typedef struct {
    char** board;
    t_dimension size;
    t_rectangle important_rectangle;
} t_game;

typedef struct {
    t_mlx_objects *mlx_objects;
    t_surface *render_surface;
    t_game* game;
} t_render_input;

int render(t_render_input* params)
{
    printf("Loop Event\n");
    put_rectangle(params->render_surface, &params->game->important_rectangle, CORNFLOWER_BLUE);
    mlx_put_image_to_window(params->mlx_objects->mlx, params->mlx_objects->window, params->render_surface->img, 0, 0);
    return IRRELEVANT_RETURN_VALUE;
}

int main(void)
{
    t_mlx_objects mlx_objects;
    mlx_objects.mlx = mlx_init();
    mlx_objects.window = mlx_new_window(mlx_objects.mlx, WIDTH, HEIGHT, WINDOW_NAME);

    t_surface render_surface;
    render_surface.img = mlx_new_image(mlx_objects.mlx, WIDTH, HEIGHT);
    render_surface.addr = mlx_get_data_addr(render_surface.img, &render_surface.bpp, &render_surface.line_length, &render_surface.endian);

    t_rectangle rect = rectangle(position(5, 5), dimension(420, 69));
    
    t_game game = (t_game){NULL, dimension(0, 0), rect};

    t_render_input render_input = (t_render_input){&mlx_objects, &render_surface, &game};

    mlx_key_hook(mlx_objects.window, handle_key_events, &mlx_objects);
    mlx_expose_hook(mlx_objects.window, render, &render_input);
    mlx_loop(mlx_objects.mlx);
}
