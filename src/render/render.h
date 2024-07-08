/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:16:30 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 12:16:45 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "game/t_game.h"
# include "hooks/hooks.h"
# include "image.h"
# include "sprites.h"
# include "t_mlx.h"

int		render(t_render_input *params);
void	render_image(t_mlx *mlx, t_image image, t_position position);

#endif
