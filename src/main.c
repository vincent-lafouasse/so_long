#include <stdio.h>
#include "mlx.h"

#define WIDTH 600
#define HEIGHT 480

int main(void)
{
    void* mlx = mlx_init();
    void* mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "a window");

    mlx_loop(mlx);
}
