/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:26:40 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/09 19:28:47 by poss             ###   ########.fr       */
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
bool		sprites_are_invalid(t_sprites sprites);
void		clear_sprites_checked(t_sprites sprites, t_mlx mlx);

#endif
