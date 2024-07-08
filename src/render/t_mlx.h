/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:25:37 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 12:26:18 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_H
# define T_MLX_H

# include "geometry/geometry.h"
# include "mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}			t_mlx;

typedef int	t_keycode;

t_mlx		init_mlx(t_dimension window_size, const char *window_name);

#endif
