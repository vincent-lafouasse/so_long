/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:31:25 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 13:05:49 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUERY_GAME_H
# define QUERY_GAME_H

# include "t_game.h"

bool	is_wall(t_position position, const t_game *game);
bool	is_player(t_position position, const t_game *game);
bool	is_exit(t_position position, const t_game *game);
bool	is_collectible(t_position position, const t_game *game);
bool	is_empty(t_position position, const t_game *game);

#endif
