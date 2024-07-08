/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:11:23 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 12:13:43 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "background.h"
#include "geometry/geometry.h"

static void	fill_background(t_image background, const t_game *game,
				const t_sprites *sprites, size_t tile_size);
static void	render_image_on_image(t_image source, t_image dest,
				t_position render_position);

t_image	make_background(const t_game *game, const t_sprites *sprites,
		t_mlx *mlx, size_t tile_size)
{
	t_image	background;

	background.size = dimension_scale(game->size, tile_size);
	background.img = mlx_new_image(mlx->mlx, background.size.w,
			background.size.h);
	background.addr = mlx_get_data_addr(background.img, &background.bpp,
			&background.line_length, &background.endianness);
	fill_background(background, game, sprites, tile_size);
	return (background);
}

static void	fill_background(t_image background, const t_game *game,
		const t_sprites *sprites, size_t tile_size)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->size.h)
	{
		col = 0;
		while (col < game->size.w)
		{
			if (game->board[row][col] == game->charset.WALL)
				render_image_on_image(sprites->wall, background, position(col
						* tile_size, row * tile_size));
			else if ((game->board[row][col] == game->charset.EMPTY)
				|| (game->board[row][col] == game->charset.COLLECTIBLE))
				render_image_on_image(sprites->floor, background, position(col
						* tile_size, row * tile_size));
			col++;
		}
		row++;
	}
}

static void	render_image_on_image(t_image source, t_image dest,
		t_position render_position)
{
	void	*source_pixel;
	void	*dst_pixel;
	int		row;
	int		col;

	row = 0;
	while (row < source.size.h)
	{
		col = 0;
		while (col < source.size.w)
		{
			source_pixel = source.addr + flatten_2d_position(position(col, row),
					source.line_length, source.bpp);
			dst_pixel = dest.addr
				+ flatten_2d_position(position(render_position.x + col,
						render_position.y + row), dest.line_length, dest.bpp);
			*(unsigned int *)dst_pixel = *(unsigned int *)source_pixel;
			col++;
		}
		row++;
	}
}
