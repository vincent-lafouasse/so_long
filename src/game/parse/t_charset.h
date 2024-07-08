/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_charset.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:46:05 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 12:47:49 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CHARSET_H
# define T_CHARSET_H

# include <stdbool.h>

# define DEFAULT_CHARSET "01CEP"

typedef struct s_charset
{
	char	empty;
	char	wall;
	char	collectible;
	char	exit;
	char	player;
}			t_charset;

t_charset	default_charset(void);
bool		is_in_charset(char c, t_charset charset);

#endif
