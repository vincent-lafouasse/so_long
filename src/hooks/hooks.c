/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:36:16 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/12 21:46:32 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game/update/update_game.h"
#include "hooks.h"
#include "render/background.h"
#include "render/render.h"
#include <X11/keysym.h>

#define IRRELEVANT_RETURN_VALUE 0

int	key_hook(t_keycode keycode, t_update_input *input)
{
	if (keycode == XK_Escape)
		exit_hook(input->mlx);
	update_game(input->game, keycode);
	*(input->needs_refresh) = true;
	return (IRRELEVANT_RETURN_VALUE);
}

int	loop_hook(t_render_input *params)
{
	if (params->game->done)
	{
		ft_printf("gg my guy\n");
		exit_hook(params->mlx);
	}
	if (params->needs_refresh == false)
		return (IRRELEVANT_RETURN_VALUE);
	render(params);
	params->needs_refresh = false;
	return (IRRELEVANT_RETURN_VALUE);
}

int	exit_hook(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx);
	return (IRRELEVANT_RETURN_VALUE);
}

t_render_input	build_render_input(t_mlx *mlx, const t_game *game,
		const t_sprites *sprites, size_t tile_size)
{
	t_render_input	render_input;

	render_input.mlx = mlx;
	render_input.game = game;
	render_input.sprites = sprites;
	render_input.needs_refresh = true;
	render_input.background = make_background(game, sprites, mlx, tile_size);
	return (render_input);
}

t_update_input		build_update_input(t_mlx* mlx, t_game* game, t_render_input* render_input)
{
	t_update_input	update_input;

	update_input.game = game;
	update_input.mlx = mlx;
	update_input.needs_refresh = &render_input->needs_refresh;
	return (update_input);
}
