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

void put_rectangle(t_surface* surface, t_rectangle rect, t_u32 color)
{
    for (int col = 0; col < rect.size.w; col++)
    {
        for (int row = 0; row < rect.size.h; row++)
            my_mlx_pixel_put(surface, position(rect.start.x + col, rect.start.y + row),color);
    }
}

typedef struct {
    void* mlx;
    void* window;
} t_mlx_objects;

int handle_key_events(t_keycode keycode, t_mlx_objects* mlx_objects)
{
    if (keycode == XK_Escape)
        mlx_destroy_window(mlx_objects->mlx, mlx_objects->window);
    if (keycode == XK_p)
        mlx_string_put(mlx_objects->mlx, mlx_objects->window, 69, 420, RED, "hello");
    return IRRELEVANT_RETURN_VALUE;
}

int main(void)
{
    t_mlx_objects mlx_objects;
    mlx_objects.mlx = mlx_init();
    mlx_objects.window = mlx_new_window(mlx_objects.mlx, WIDTH, HEIGHT, WINDOW_NAME);

    t_surface surface;
    surface.img = mlx_new_image(mlx_objects.mlx, WIDTH, HEIGHT);
    surface.addr = mlx_get_data_addr(surface.img, &surface.bpp, &surface.line_length, &surface.endian);

    t_rectangle rect = {{5, 5}, {200, 69}};
    put_rectangle(&surface, rect, CORNFLOWER_BLUE);

    mlx_put_image_to_window(mlx_objects.mlx, mlx_objects.window, surface.img, 0, 0);

    mlx_key_hook(mlx_objects.window, handle_key_events, &mlx_objects);
    mlx_loop(mlx_objects.mlx);
}
