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

bool position_eq(t_position a, t_position b)
{
    return position_compare(a, b) == 0;
}

t_position position_scale(t_position pos, size_t scaling_factor)
{
    return (t_position){.x = pos.x * scaling_factor, .y = pos.y * scaling_factor};
}

t_dimension dimension_scale(t_dimension dim, size_t scaling_factor)
{
    return (t_dimension){.w = dim.w * scaling_factor, .h = dim.h * scaling_factor};
}

int flatten_2d_position(t_position position,
                        int line_length,
                        int bits_per_pixel)
{
    return position.y * line_length + position.x * (bits_per_pixel / 8);
}
