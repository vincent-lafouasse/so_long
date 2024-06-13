#include "image.h"

t_mlx init_mlx(t_dimension window_size, const char* window_name)
{
    t_mlx mlx;
    mlx.mlx = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx, window_size.w, window_size.h,
                                (char*)window_name);
    return mlx;
}

t_image load_image_xpm(const char* path, t_mlx mlx)
{
    t_image out;
    out.img =
        mlx_xpm_file_to_image(mlx.mlx, (char*)path, &out.size.w, &out.size.h);
    out.addr =
        mlx_get_data_addr(out.img, &out.bpp, &out.line_length, &out.endianness);
    return out;
}
