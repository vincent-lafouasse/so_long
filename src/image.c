#include "image.h"

void my_mlx_pixel_put(t_image* surface, t_position px_pos, t_u32 color)
{
    char* dst = surface->addr +
                flatten_2d_position(px_pos, surface->line_length, surface->bpp);
    *(t_u32*)dst = color;
}

void put_rectangle(t_image* surface, t_rectangle rect, t_u32 color)
{
    for (int col = 0; col < rect.size.w; col++)
    {
        for (int row = 0; row < rect.size.h; row++)
            my_mlx_pixel_put(surface,
                             position(rect.start.x + col, rect.start.y + row),
                             color);
    }
}
t_mlx init_mlx(t_dimension window_size, const char* window_name)
{
    t_mlx mlx;
    mlx.mlx = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx, window_size.w, window_size.h,
                                (char*)window_name);
    return mlx;
}

t_image init_empty_image(t_dimension size, t_mlx* mlx)
{
    t_image out;

    out.img = mlx_new_image(mlx->mlx, size.w, size.h);
    out.addr =
        mlx_get_data_addr(out.img, &out.bpp, &out.line_length, &out.endian);
    return out;
}

t_image load_image_xpm(const char* path, t_mlx* mlx)
{
    t_image out;
    out.img =
        mlx_xpm_file_to_image(mlx->mlx, (char*)path, &out.size.w, &out.size.h);
    out.addr =
        mlx_get_data_addr(out.img, &out.bpp, &out.line_length, &out.endian);
    return out;
}
