/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:16:59 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 13:08:21 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/query_game.h"
#include "geometry/geometry.h"
#include "image.h"
#include "render.h"
#include "render/sprites.h"
#include "t_mlx.h"

#define IRRELEVANT_RETURN_VALUE 0

static void	render_collectibles(t_render_input *in);
static void	render_background(t_render_input *in);
static void	render_player(t_render_input *in);
static void	render_exit(t_render_input *in);

int	render(t_render_input *params)
{
	render_background(params);
	render_collectibles(params);
	if (params->game->n_collectibles == 0)
		render_exit(params);
	render_player(params);
	return (IRRELEVANT_RETURN_VALUE);
}

static void	render_collectibles(t_render_input *in)
{
	int			row;
	int			col;
	t_position	current;

	row = 0;
	while (row < in->game->size.h)
	{
		col = 0;
		while (col < in->game->size.w)
		{
			current = position(col, row);
			if (is_collectible(current, in->game))
				render_image(in->mlx, in->sprites->collectible,
					position_scale(position(col, row), TILE_SIZE));
			col++;
		}
		row++;
	}
}

static void	render_background(t_render_input *in)
{
	render_image(in->mlx, in->background, position(0, 0));
}

static void	render_player(t_render_input *in)
{
	render_image(in->mlx, in->sprites->player, position_scale(in->game->player,
			TILE_SIZE));
}

static void	render_exit(t_render_input *in)
{
	render_image(in->mlx, in->sprites->exit, position_scale(in->game->exit,
			TILE_SIZE));
}
