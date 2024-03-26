#include <stdio.h>
#include <stdint.h>
#include "mlx.h"

#define WIDTH 600
#define HEIGHT 480

typedef struct {
    void* img;
    char* addr;
    int bpp;
    int line_length;
    int endian;
} t_data;

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

    t_data img;
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
}
