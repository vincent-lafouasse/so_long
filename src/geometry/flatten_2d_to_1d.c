/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flatten_2d_to_1d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:38:22 by vlafouas          #+#    #+#             */
/*   Updated: 2024/06/13 17:38:33 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

int flatten_2d_position(t_position position,
                        int line_length,
                        int bits_per_pixel)
{
    return position.y * line_length + position.x * (bits_per_pixel / 8);
}
