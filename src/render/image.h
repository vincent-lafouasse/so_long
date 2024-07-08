/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:15:02 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 12:21:44 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "geometry/geometry.h"
# include "t_mlx.h"

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endianness;
	t_dimension	size;
}				t_image;

t_image			load_image_xpm(const char *path, t_mlx mlx);
void			render_image(t_mlx *mlx, t_image image, t_position position);

#endif
