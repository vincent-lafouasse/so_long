#include "geometry.h"

t_position position(int x, int y)
{
    return (t_position){x, y};
}

t_dimension dimension(int w, int h)
{
    return (t_dimension){w, h};
}

int position_compare(t_position a, t_position b)
{
    if (a.x > b.x)
        return 1;
    if (a.x < b.x)
        return -1;
    if (a.y > b.y)
        return 1;
    if (a.y < b.y)
        return -1;
    return 0;
}

int dimension_compare(t_dimension a, t_dimension b)
{
    if (a.w > b.w)
        return 1;
    if (a.w < b.w)
        return -1;
    if (a.h > b.h)
        return 1;
    if (a.h < b.h)
        return -1;
    return 0;
}

t_rectangle rectangle(t_position start, t_dimension size)
{
    return (t_rectangle){start, size};
}

int flatten_2d_position(t_position position,
                        int line_length,
                        int bits_per_pixel)
{
    return position.y * line_length + position.x * (bits_per_pixel / 8);
}
