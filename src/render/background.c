#include "background.h"
#include "geometry/geometry.h"
#include "mlx_int.h"
#include "render/render.h"

static void render_image_on_image(t_image source, t_image dest,  t_position render_position)
{
    void* source_pixel;
    void* dst_pixel;

    for (int row = 0; row < source.size.h; row++)
    {
        for (int col = 0; col < source.size.w; col++)
        {
            source_pixel = source.addr + flatten_2d_position(position(col, row), source.line_length, source.bpp);
            dst_pixel = dest.addr + flatten_2d_position(position(render_position.x + col, render_position.y + row), dest.line_length, dest.bpp);
            *(unsigned int*)dst_pixel = *(unsigned int*)source_pixel;
        }
    }
}


t_image make_background(const t_game* game, const t_sprites* sprites, t_mlx* mlx,  size_t tile_size)
{
    //render_image(t_mlx *mlx, const t_image *image, t_position position)
    t_image background;
    background.size = dimension_scale(game->size, tile_size);
    background.img = mlx_new_image(mlx->mlx, background.size.w, background.size.h);
    background.addr = mlx_get_data_addr(background.img, &background.bpp, &background.line_length, &background.endianness);

    render_image_on_image(sprites->wall, background, position(4, 20));

    return background;
}
