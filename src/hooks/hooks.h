/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:21:12 by vlafouas          #+#    #+#             */
/*   Updated: 2024/06/13 17:24:06 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "game/t_game.h"
#include "render/t_mlx.h"
#include "render/sprites.h"

typedef struct
{
    t_game* game;
    t_mlx* mlx;
    bool* needs_refresh;
} t_update_input;

typedef struct
{
    t_mlx* mlx;
    const t_game* game;
    const t_sprites* sprites;
    t_image background;
    bool needs_refresh;
} t_render_input;

t_render_input	build_render_input(t_mlx *mlx, const t_game *game,
        const t_sprites *sprites, size_t tile_size);

int				exit_hook(t_mlx *mlx);
int				key_hook(t_keycode keycode, t_update_input *input);
int				loop_hook(t_render_input *params);
