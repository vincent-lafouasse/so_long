/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:07:23 by poss              #+#    #+#             */
/*   Updated: 2024/06/17 10:35:15 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load/t_map.h"
#include "parse/parse_map.h"
#include "t_game.h"

t_game	init_game(const char *map_path, t_charset charset)
{
	t_game		game;
	t_map	raw_map;

	raw_map = load_raw_map(map_path);
	game.board = raw_map.data;
	game.size = raw_map.size;
	game.charset = charset;
	game.n_collectibles = 0;
	game.move_count = 0;
	parse_map(&game);
	game.done = false;
	return (game);
}
