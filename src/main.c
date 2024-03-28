#include <stdio.h>
#include <stdint.h>
#include <X11/keysym.h>
#include "mlx.h"
#include "cool_ints.h"

#define WIDTH 600
#define HEIGHT 480
#define WINDOW_NAME ("idk, a name ig")
#define RED (0x00FF0000)
#define CORNFLOWER_BLUE (0x006495ED)

typedef int t_keycode;

typedef struct {
    void* img;
    char* addr;
    int bpp;
    int line_length;
    int endian;
} t_data;

typedef struct {
    int x;
    int y;
} t_px_position;


typedef struct {
    int w;
    int h;
} t_px_dimension;

typedef struct {
    t_px_position start;
    t_px_dimension size;
} t_rectangle;

t_px_position px_position(int x, int y)
{
    return (t_px_position){x, y};
}

int offset(t_px_position px_pos, t_data* data)
{
    return px_pos.y * data->line_length + px_pos.x * (data->bpp / 8);
}

void my_mlx_pixel_put(t_data* data, t_px_position px_pos,  int color)
{
    char* dst = data->addr + offset(px_pos, data);
    *(t_u32*)dst = color;
}

void put_rectangle(t_data* data, t_rectangle rect, t_u32 color)
{
    for (int col = 0; col < rect.size.w; col++)
    {
        for (int row = 0; row < rect.size.h; row++)
            my_mlx_pixel_put(data, px_position(rect.start.x + col, rect.start.y + row),color);
    }
}

typedef struct {
    void* mlx;
    void* window;
} t_vars;

int very_cool_hook(t_keycode keycode, t_vars* vars)
{
    (void)keycode;
    (void)vars;
    //mlx_destroy_window(vars->mlx, vars->window);
    printf("keypress detected\n");
    return 0;
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

    mlx_key_hook(vars.window, very_cool_hook, &vars);
    mlx_loop(vars.mlx);
}
