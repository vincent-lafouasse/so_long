/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:42:44 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/11 15:31:29 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map.h"
#include <stdlib.h>

void	free_map(t_map map)
{
	int	row;

	if (!map.data)
		return ;
	row = 0;
	while (row < map.size.h)
	{
		if (map.data[row])
			free(map.data[row]);
		row++;
	}
	free(map.data);
}
