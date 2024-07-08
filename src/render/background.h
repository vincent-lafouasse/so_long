/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:14:04 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 12:14:25 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_H
# define BACKGROUND_H

# include "game/t_game.h"
# include "sprites.h"

t_image	make_background(const t_game *game, const t_sprites *sprites,
			t_mlx *mlx, size_t tile_size);

#endif
