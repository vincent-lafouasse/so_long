/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_traversal_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:25:51 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 13:35:54 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "parse_internals.h"
#include <stdlib.h>

bool	is_reached(const char **reached, t_position position,
		const t_game *game)
{
	if (!is_walkable(position, game))
		return (false);
	return (reached[position.y][position.x] == 'R');
}

bool	is_walkable(t_position pos, const t_game *game)
{
	if (pos.x >= game->size.w || pos.x < 0 || pos.y >= game->size.h
		|| pos.y < 0)
		return (false);
	return (game->board[pos.y][pos.x] != game->charset.wall);
}

char	**deep_copy_map(const t_game *game)
{
	char	**copy;
	int		row;

	copy = malloc(sizeof(char *) * game->size.h);
	if (!copy)
		return (NULL);
	row = 0;
	while (row < game->size.h)
	{
		copy[row] = ft_strdup(game->board[row]);
		row++;
	}
	return (copy);
}
