/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dimension.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:39:43 by vlafouas          #+#    #+#             */
/*   Updated: 2024/06/13 17:39:44 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_dimension	dimension(int w, int h)
{
	return ((t_dimension){w, h});
}

t_dimension	dimension_scale(t_dimension dim, size_t scaling_factor)
{
	return ((t_dimension){.w = dim.w * scaling_factor, .h = dim.h
		* scaling_factor});
}
