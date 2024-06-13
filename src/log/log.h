/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:41:50 by vlafouas          #+#    #+#             */
/*   Updated: 2024/06/13 17:42:10 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "game/t_game.h"
# include "libft/t_list.h"
# include "render/t_mlx.h"

void	log_time(void);
void	log_key_event(t_keycode keycode);
void	log_loop_event(void);

void	log_str_lst(const t_list *strs);
void	log_char_matrix(const char **matrix, t_dimension size);
void	log_game(t_game game);
void	log_pos(t_position pos);

void	ascii_render(const t_game *game);

#endif
