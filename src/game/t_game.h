/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:28:11 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 15:17:07 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GAME_H
# define T_GAME_H

# include "geometry/geometry.h"
# include "parse/t_charset.h"
# include <stdbool.h>

typedef struct s_game
{
	char		**board;
	t_dimension	size;
	t_position	player;
	t_position	exit;
	size_t		n_collectibles;
	size_t		move_count;
	t_charset	charset;
	bool		done;
}				t_game;

t_game			init_game(const char *map_path, t_charset charset);
void			free_game(t_game *game);

#endif
