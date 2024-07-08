/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:32:00 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 15:05:09 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "query_game.h"

bool	is_player(t_position position, const t_game *game)
{
	return (position_eq(position, game->player));
}

bool	is_exit(t_position position, const t_game *game)
{
	return (position_eq(position, game->exit));
}

bool	is_collectible(t_position position, const t_game *game)
{
	return (game->board[position.y][position.x] == game->charset.collectible);
}

bool	is_wall(t_position position, const t_game *game)
{
	return (game->board[position.y][position.x] == game->charset.wall);
}

bool	is_empty(t_position position, const t_game *game)
{
	return (game->board[position.y][position.x] == game->charset.empty);
}
