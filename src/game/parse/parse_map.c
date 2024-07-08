/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:14:51 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 13:22:30 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/error.h"
#include "game/query_game.h"
#include "parse_map.h"
#include "t_charset.h"
#include <stddef.h>

static bool	map_is_enclosed_in_walls(const t_game *game);
static bool	map_has_enough_tokens(const t_game *game);
static void	map_parse_tokens(t_game *game);
static void	map_parse_position(t_game *game, t_position pos);

void	parse_map(t_game *game)
{
	if (!map_is_enclosed_in_walls(game))
	{
		free_game(game);
		die("Map is not enclosed in walls");
	}
	if (!map_has_enough_tokens(game))
	{
		free_game(game);
		die("Invalid map tokens");
	}
	game->n_collectibles = 0;
	map_parse_tokens(game);
	if (position_compare(game->exit, position(0, 0)) == 0)
	{
		free_game(game);
		die("Failed to parse map tokens");
	}
	if (!has_valid_path(game))
	{
		free_game(game);
		die("Map has unreachable tokens");
	}
}

static bool	map_is_enclosed_in_walls(const t_game *game)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (col < game->size.w)
	{
		if (!is_wall(position(col, 0), game))
			return (false);
		if (!is_wall(position(col, game->size.h - 1), game))
			return (false);
		col++;
	}
	while (row < game->size.h)
	{
		if (!is_wall(position(0, row), game))
			return (false);
		if (!is_wall(position(game->size.w - 1, row), game))
			return (false);
		row++;
	}
	return (true);
}

static bool	map_has_enough_tokens(const t_game *game)
{
	size_t	n_collectibles;
	size_t	n_exit;
	size_t	n_player;
	int		row;
	int		col;

	n_collectibles = 0;
	n_exit = 0;
	n_player = 0;
	row = 0;
	while (row < game->size.h)
	{
		col = 0;
		while (col < game->size.w)
		{
			if (!is_in_charset(game->board[row][col], game->charset))
				return (false);
			n_collectibles += is_collectible(position(col, row), game);
			n_exit += is_exit(position(col, row), game);
			n_player += is_player(position(col, row), game);
			col++;
		}
		row++;
	}
	return ((n_exit == 1) && (n_player == 1) && (n_collectibles >= 1));
}

static void	map_parse_tokens(t_game *game)
{
	t_position	current;

	current.y = 0;
	while (current.y < game->size.h)
	{
		current.x = 0;
		while (current.x < game->size.w)
		{
			map_parse_position(game, current);
			current.x++;
		}
		current.y++;
	}
}

static void	map_parse_position(t_game *game, t_position pos)
{
	if (is_exit(pos, game))
	{
		game->exit = pos;
		game->board[pos.y][pos.x] = game->charset.empty;
	}
	if (is_player(pos, game))
	{
		game->player = pos;
		game->board[pos.y][pos.x] = game->charset.empty;
	}
	if (is_collectible(pos, game))
	{
		game->n_collectibles += 1;
	}
}
