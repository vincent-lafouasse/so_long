/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_internals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:09:01 by poss              #+#    #+#             */
/*   Updated: 2024/06/13 20:09:32 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_INTERNALS_H
# define LOAD_INTERNALS_H

# include "t_raw_map.h"

t_raw_map	load_raw_map(const char *path);

// in string_utils.c
void		trim_trailing_newline(char *s);
bool		str_ends_with(const char *s, const char *pattern);

#endif
