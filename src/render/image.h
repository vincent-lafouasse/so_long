#pragma once

#include "geometry/geometry.h"
#include "t_mlx.h"

typedef struct
{
    void* img;
    char* addr;
    int bpp;
    int line_length;
    int endian;
    t_dimension size;
} t_image;

t_image load_image_xpm(const char* path, t_mlx mlx);
