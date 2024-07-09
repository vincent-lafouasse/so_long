/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:27:11 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/09 19:36:10 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/image.h"
#include "sprites.h"

#define PLAYER_XPM "./assets/sprites/player.xpm"
#define COLLECTIBLE_XPM "./assets/sprites/collectible.xpm"
#define EXIT_XPM "./assets/sprites/exit.xpm"
#define FLOOR_XPM "./assets/sprites/floor.xpm"
#define WALL_XPM "./assets/sprites/wall.xpm"

static t_sprites invalid_sprites(void);
static bool		sprites_are_valid(t_sprites sprites);

t_sprites	load_sprites(t_mlx mlx)
{
	t_sprites	sprites;

	sprites.player = load_image_xpm(PLAYER_XPM, mlx);
	sprites.collectible = load_image_xpm(COLLECTIBLE_XPM, mlx);
	sprites.exit = load_image_xpm(EXIT_XPM, mlx);
	sprites.floor = load_image_xpm(FLOOR_XPM, mlx);
	sprites.wall = load_image_xpm(WALL_XPM, mlx);
	if (!sprites_are_valid(sprites))
	{
		clear_sprites_checked(sprites, mlx);
		return (invalid_sprites());
	}
	return (sprites);
}

static bool		sprites_are_valid(t_sprites sprites)
{
	if (!sprites.player.img)
		return false;
	if (!sprites.wall.img)
		return false;
	if (!sprites.floor.img)
		return false;
	if (!sprites.exit.img)
		return false;
	if (!sprites.collectible.img)
		return false;
	return true;
}

void		clear_sprites_checked(t_sprites sprites, t_mlx mlx)
{
	if (sprites.exit.img)
		mlx_destroy_image(mlx.mlx, sprites.exit.img);
	if (sprites.player.img)
		mlx_destroy_image(mlx.mlx, sprites.player.img);
	if (sprites.wall.img)
		mlx_destroy_image(mlx.mlx, sprites.wall.img);
	if (sprites.floor.img)
		mlx_destroy_image(mlx.mlx, sprites.floor.img);
	if (sprites.collectible.img)
		mlx_destroy_image(mlx.mlx, sprites.collectible.img);
}

static t_sprites invalid_sprites(void)
{
	t_sprites out;

	out.player.img = NULL;
	return out;
}

bool		sprites_are_invalid(t_sprites sprites)
{
	return (sprites.player.img == NULL);
}
