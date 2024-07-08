/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:26:40 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 12:26:57 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# include "image.h"

# define TILE_SIZE 64

typedef struct s_sprites
{
	t_image	wall;
	t_image	floor;
	t_image	player;
	t_image	collectible;
	t_image	exit;
}			t_sprites;

t_sprites	load_sprites(t_mlx mlx);

#endif
