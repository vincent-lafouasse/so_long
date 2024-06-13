/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_position.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:39:02 by vlafouas          #+#    #+#             */
/*   Updated: 2024/06/13 17:39:19 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_position	position(int x, int y)
{
	return ((t_position){x, y});
}

int	position_compare(t_position a, t_position b)
{
	if (a.x > b.x)
		return (1);
	if (a.x < b.x)
		return (-1);
	if (a.y > b.y)
		return (1);
	if (a.y < b.y)
		return (-1);
	return (0);
}

bool	position_eq(t_position a, t_position b)
{
	return (position_compare(a, b) == 0);
}

t_position	position_scale(t_position pos, size_t scaling_factor)
{
	return ((t_position){.x = pos.x * scaling_factor, .y = pos.y
		* scaling_factor});
}
