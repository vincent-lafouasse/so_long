#include "background.h"
#include "mlx_int.h"

t_image make_background(const t_game* game, const t_sprites* sprites, t_mlx* mlx,  size_t tile_size)
{
    t_image background;
    background.size = dimension_scale(game->size, tile_size);
    background.img = mlx_new_image(mlx->mlx, background.size.w, background.size.h);
    background.addr = mlx_get_data_addr(background.img, &background.bpp, &background.line_length, &background.endianness);

    return background;
}
