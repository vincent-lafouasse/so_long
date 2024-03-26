#include <stdio.h>
#include <stdint.h>
#include "mlx.h"

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
} t_pixel_position;

int offset(int x, int y, t_data* data)
{
    return y * data->line_length + x * (data->bpp / 8);
}

void my_mlx_pixel_put(t_data* data, int x, int y,  int color)
{
    char* dst = data->addr + offset(x, y, data);
    *(uint32_t*)dst = color;
}

int main(void)
{
    void* mlx = mlx_init();
    void* mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, WINDOW_NAME);

    t_data img;
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
    my_mlx_pixel_put(&img, 5, 5, CORNFLOWER_BLUE);

    mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
    mlx_loop(mlx);
}
