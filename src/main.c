/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:01:01 by poss              #+#    #+#             */
/*   Updated: 2024/07/12 03:48:35 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/error.h"
#include "game/parse/t_charset.h"
#include "game/t_game.h"
#include "geometry/geometry.h"
#include "hooks/hooks.h"
#include "mlx.h"
#include "render/sprites.h"
#include <X11/X.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data t_data;
struct s_data {
	t_game *game;
	t_mlx *mlx;
	t_sprites *sprites;
	t_image *background;
};

static void cleanup_and_exit(t_data data, const char* msg);

int	main(int ac, char **av)
{
	t_game			game;
	t_mlx			mlx;
	t_sprites		sprites;
	t_render_input	render_input;
	t_update_input	update_input;

	if (ac != 2)
		die("Usage: ./so_long map.ber");
	game = init_game(av[1], default_charset());
	mlx = init_mlx(dimension_scale(game.size, TILE_SIZE), "a cool game");
	if (!mlx.mlx || !mlx.window)
		cleanup_and_exit((t_data){&game, &mlx, NULL, NULL}, "Error building window");
	sprites = load_sprites(mlx);
	if (sprites_are_invalid(sprites))
		cleanup_and_exit((t_data){&game, &mlx, &sprites, NULL}, "Error loading sprites");
	render_input = build_render_input(&mlx, &game, &sprites, TILE_SIZE);
	update_input = (t_update_input){&game, &mlx,
		.needs_refresh = &render_input.needs_refresh};
	mlx_hook(mlx.window, DestroyNotify, StructureNotifyMask, exit_hook, &mlx);
	mlx_key_hook(mlx.window, &key_hook, &update_input);
	mlx_loop_hook(mlx.mlx, &loop_hook, &render_input);
	mlx_loop(mlx.mlx);
	cleanup_and_exit((t_data){&game, &mlx, &sprites, &render_input.background}, NULL);
}

static void cleanup_and_exit(t_data data, const char* msg)
{
	if (!data.mlx)
		return ;
	if (data.background)
		mlx_destroy_image(data.mlx->mlx, data.background->img);
	if (data.sprites)
		clear_sprites_checked(*(data.sprites), *(data.mlx));
	if (data.mlx->window)
		mlx_destroy_window(data.mlx->mlx, data.mlx->window);
	if (data.mlx->mlx)
	{
		mlx_destroy_display(data.mlx->mlx);
		free(data.mlx->mlx);
	}
	if (data.game)
		free_game(data.game);
	if (msg)
		die(msg);
	exit(0);
}
