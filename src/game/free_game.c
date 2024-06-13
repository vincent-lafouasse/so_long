/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:06:00 by poss              #+#    #+#             */
/*   Updated: 2024/06/13 20:06:36 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_game.h"
#include <stdlib.h>

void	free_game(t_game *game)
{
	int	row;

	row = 0;
	while (row < game->size.h)
		free(game->board[row++]);
	free(game->board);
}
