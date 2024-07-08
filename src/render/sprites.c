/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:27:11 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 12:27:15 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/image.h"
#include "sprites.h"

#define PLAYER_XPM "./assets/sprites/player.xpm"
#define COLLECTIBLE_XPM "./assets/sprites/collectible.xpm"
#define EXIT_XPM "./assets/sprites/exit.xpm"
#define FLOOR_XPM "./assets/sprites/floor.xpm"
#define WALL_XPM "./assets/sprites/wall.xpm"

t_sprites	load_sprites(t_mlx mlx)
{
	t_sprites	sprites;

	sprites.player = load_image_xpm(PLAYER_XPM, mlx);
	sprites.collectible = load_image_xpm(COLLECTIBLE_XPM, mlx);
	sprites.exit = load_image_xpm(EXIT_XPM, mlx);
	sprites.floor = load_image_xpm(FLOOR_XPM, mlx);
	sprites.wall = load_image_xpm(WALL_XPM, mlx);
	return (sprites);
}
