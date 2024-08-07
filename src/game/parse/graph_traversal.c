/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_traversal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:23:39 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/11 15:35:10 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/load/t_map.h"
#include "parse_internals.h"
#include "parse_map.h"

static void	flood_fill(char **reached, t_position start, const t_game *game);
static bool	collectibles_are_reached(const char **reached, const t_game *game);
static bool	matrix_is_valid(const char **matrix, t_dimension sz);

bool	has_valid_path(const t_game *game)
{
	char	**reached;

	reached = deep_copy_map(game);
	if (!matrix_is_valid((const char **)reached, game->size))
	{
		free_map((t_map){reached, game->size});
		return (false);
	}
	flood_fill(reached, game->player, game);
	if (!is_reached((const char **)reached, game->player, game)
		|| !is_reached((const char **)reached, game->exit, game)
		|| !collectibles_are_reached((const char **)reached, game))
	{
		free_map((t_map){reached, game->size});
		return (false);
	}
	free_map((t_map){reached, game->size});
	return (true);
}

void	flood_fill(char **reached, t_position start, const t_game *game)
{
	if (!is_walkable(start, game))
	{
		return ;
	}
	if (is_reached((const char **)reached, start, game))
	{
		return ;
	}
	reached[start.y][start.x] = 'R';
	flood_fill(reached, position(start.x + 1, start.y), game);
	flood_fill(reached, position(start.x - 1, start.y), game);
	flood_fill(reached, position(start.x, start.y + 1), game);
	flood_fill(reached, position(start.x, start.y - 1), game);
}

static bool	collectibles_are_reached(const char **reached, const t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->size.h)
	{
		col = 0;
		while (col < game->size.w)
		{
			if (game->board[row][col] == game->charset.collectible
				&& !is_reached(reached, position(col, row), game))
			{
				return (false);
			}
			col++;
		}
		row++;
	}
	return (true);
}

static bool	matrix_is_valid(const char **matrix, t_dimension sz)
{
	int	row;

	if (!matrix)
		return (false);
	row = 0;
	while (row < sz.h)
	{
		if (!matrix[row])
			return (false);
		row++;
	}
	return (true);
}
