#include "error/error.h"
#include "game/t_game.h"
#include "geometry/geometry.h"
#include "mlx.h"
#include "game/parse/t_charset.h"
#include "hooks/hooks.h"
#include <X11/X.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void			cleanup(t_mlx mlx, t_sprites sprites, t_image background);

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
	sprites = load_sprites(mlx);
	render_input = build_render_input(&mlx, &game, &sprites, TILE_SIZE);
	update_input = (t_update_input){&game, &mlx,
		.needs_refresh = &render_input.needs_refresh};
	mlx_hook(mlx.window, DestroyNotify, StructureNotifyMask, exit_hook, &mlx);
	mlx_key_hook(mlx.window, &key_hook, &update_input);
	mlx_loop_hook(mlx.mlx, &loop_hook, &render_input);
	mlx_loop(mlx.mlx);
	cleanup(mlx, sprites, render_input.background);
	free_game(&game);
}

void	cleanup(t_mlx mlx, t_sprites sprites, t_image background)
{
	mlx_destroy_image(mlx.mlx, background.img);
	mlx_destroy_image(mlx.mlx, sprites.exit.img);
	mlx_destroy_image(mlx.mlx, sprites.wall.img);
	mlx_destroy_image(mlx.mlx, sprites.player.img);
	mlx_destroy_image(mlx.mlx, sprites.collectible.img);
	mlx_destroy_image(mlx.mlx, sprites.floor.img);
	mlx_destroy_window(mlx.mlx, mlx.window);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}
