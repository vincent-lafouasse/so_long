/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_internals.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:24:19 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 13:37:49 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INTERNALS_H
# define PARSE_INTERNALS_H

# include "game/t_game.h"

bool	is_walkable(t_position pos, const t_game *game);
bool	is_reached(const char **reached, t_position position,
			const t_game *game);
char	**deep_copy_map(const t_game *game);

#endif
