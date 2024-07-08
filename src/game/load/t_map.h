/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:37:28 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 12:38:02 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "geometry/geometry.h"
# include <stdbool.h>

typedef struct s_map
{
	char		**data;
	t_dimension	size;
}				t_map;

// returns a map with NULL data if something failed
t_map			load_map(const char *map_path);
void			free_map(t_map map);

#endif
