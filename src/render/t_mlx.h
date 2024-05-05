#pragma once

#include "geometry/geometry.h"
#include "mlx.h"

typedef struct
{
    void* mlx;
    void* window;
} t_mlx;

typedef int t_keycode;

t_mlx init_mlx(t_dimension window_size, const char* window_name);
