#pragma once

#include "t_mlx.h"
#include "cool_ints.h"
#include "geometry.h"

typedef struct
{
    void* img;
    char* addr;
    int bpp;
    int line_length;
    int endian;
    t_dimension size;
} t_image;

t_image init_empty_image(t_dimension size, t_mlx* mlx);
t_image load_image_xpm(const char* path, t_mlx* mlx);
void my_mlx_pixel_put(t_image* surface, t_position px_pos, t_u32 color);
void put_rectangle(t_image* surface, t_rectangle rect, t_u32 color);
