/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:07:23 by poss              #+#    #+#             */
/*   Updated: 2024/06/17 18:43:59 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/error.h"
#include "load/t_map.h"
#include "parse/parse_map.h"
#include "t_game.h"

t_game	init_game(const char *map_path, t_charset charset)
{
	t_game	game;
	t_map	map;

	map = load_map(map_path);
	if (map.data == NULL)
		die("Failed to load map\n");
	game.board = map.data;
	game.size = map.size;
	game.charset = charset;
	parse_map(&game);
	if (map.data == NULL)
		die("Failed to parse map\n");
	game.done = false;
	game.move_count = 0;
	return (game);
}
