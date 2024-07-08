/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_charset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:33:58 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 13:34:19 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "t_charset.h"

t_charset	default_charset(void)
{
	t_charset	charset;

	charset.empty = '0';
	charset.wall = '1';
	charset.collectible = 'C';
	charset.exit = 'E';
	charset.player = 'P';
	return (charset);
}

bool	is_in_charset(char c, t_charset charset)
{
	return ((charset.wall == c) || (charset.empty == c) || (charset.player == c)
		|| (charset.exit == c) || (charset.collectible == c));
}
