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
} t_data;

void my_mlx_pixel_put(t_data* data, t_position px_pos,  t_u32 color)
{
    char* dst = data->addr + flatten_2d_position(px_pos, data->line_length, data->bpp);
    *(t_u32*)dst = color;
}

void put_rectangle(t_data* data, t_rectangle rect, t_u32 color)
{
    for (int col = 0; col < rect.size.w; col++)
    {
        for (int row = 0; row < rect.size.h; row++)
            my_mlx_pixel_put(data, position(rect.start.x + col, rect.start.y + row),color);
    }
}

typedef struct {
    void* mlx;
    void* window;
} t_vars;

int handle_key_events(t_keycode keycode, t_vars* vars)
{
    if (keycode == XK_Escape)
        mlx_destroy_window(vars->mlx, vars->window);
    if (keycode == XK_p)
        mlx_string_put(vars->mlx, vars->window, 69, 420, RED, "hello");
    return IRRELEVANT_RETURN_VALUE;
}

int main(void)
{
    t_vars vars;
    vars.mlx = mlx_init();
    vars.window = mlx_new_window(vars.mlx, WIDTH, HEIGHT, WINDOW_NAME);

    t_data img;
    img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);

    t_rectangle rect = {{5, 5}, {200, 69}};
    put_rectangle(&img, rect, CORNFLOWER_BLUE);

    mlx_put_image_to_window(vars.mlx, vars.window, img.img, 0, 0);

    mlx_key_hook(vars.window, handle_key_events, &vars);
    mlx_loop(vars.mlx);
}
