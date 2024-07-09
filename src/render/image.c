/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:16:02 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/09 19:34:37 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

t_mlx	init_mlx(t_dimension window_size, const char *window_name)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, window_size.w, window_size.h,
			(char *)window_name);
	return (mlx);
}

t_image	load_image_xpm(const char *path, t_mlx mlx)
{
	t_image	out;

	out.img = mlx_xpm_file_to_image(mlx.mlx, (char *)path, &out.size.w,
			&out.size.h);
	if (!out.img)
		return (out);
	out.addr = mlx_get_data_addr(out.img, &out.bpp, &out.line_length,
			&out.endianness);
	return (out);
}

void	render_image(t_mlx *mlx, t_image image, t_position position)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, image.img, position.x,
		position.y);
}
