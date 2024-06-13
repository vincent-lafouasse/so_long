/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:37:53 by vlafouas          #+#    #+#             */
/*   Updated: 2024/06/13 17:37:54 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_position
{
	int		x;
	int		y;
}			t_position;

typedef struct s_dimension
{
	int		w;
	int		h;
}			t_dimension;

t_position	position(int x, int y);
int			position_compare(t_position a, t_position b);
bool		position_eq(t_position a, t_position b);
t_position	position_scale(t_position pos, size_t scaling_factor);

t_dimension	dimension(int w, int h);
t_dimension	dimension_scale(t_dimension dim, size_t scaling_factor);

int			flatten_2d_position(t_position position, int line_length,
				int bits_per_pixel);

#endif
