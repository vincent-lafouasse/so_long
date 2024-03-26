#include <stdio.h>
#include <stdint.h>
#include "mlx.h"
#include "cool_ints.h"

#define WIDTH 600
#define HEIGHT 480
#define WINDOW_NAME ("idk, a name ig")
#define RED (0x00FF0000)
#define CORNFLOWER_BLUE (0x006495ED)

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

int main(void)
{
    void* mlx = mlx_init();
    void* mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, WINDOW_NAME);

    t_data img;
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
    my_mlx_pixel_put(&img, px_position(5, 5), CORNFLOWER_BLUE);

    mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
    mlx_loop(mlx);
}
