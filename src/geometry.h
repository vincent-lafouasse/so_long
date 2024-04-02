#pragma once

typedef struct
{
    int x;
    int y;
} t_position;

typedef struct
{
    int w;
    int h;
} t_dimension;

typedef struct
{
    t_position start;
    t_dimension size;
} t_rectangle;

t_position position(int x, int y);
t_dimension dimension(int w, int h);
t_rectangle rectangle(t_position start, t_dimension size);

int flatten_2d_position(t_position position,
                        int line_length,
                        int bits_per_pixel);
