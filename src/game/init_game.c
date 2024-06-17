/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:07:23 by poss              #+#    #+#             */
/*   Updated: 2024/06/17 10:40:31 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load/t_map.h"
#include "parse/parse_map.h"
#include "t_game.h"

t_game	init_game(const char *map_path, t_charset charset)
{
	t_game		game;
	t_map		map;

	map = load_map(map_path);
	game.board = map.data;
	game.size = map.size;
	game.charset = charset;
	game.n_collectibles = 0;
	game.move_count = 0;
	parse_map(&game);
	game.done = false;
	return (game);
}
