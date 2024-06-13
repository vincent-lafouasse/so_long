/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:42:56 by poss              #+#    #+#             */
/*   Updated: 2024/06/13 17:44:46 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/query_game.h"
#include "libft/ft_io.h"
#include "log.h"
#include <X11/keysym.h>
#include <stdio.h>

void	log_game(t_game game)
{
	printf("Game\n");
	printf("Board\t w%d h%d\n", game.size.w, game.size.h);
	log_char_matrix((const char **)game.board, game.size);
	printf("Player\t x%d y%d\n", game.player.x, game.player.y);
	printf("Exit\t x%d y%d\n", game.exit.x, game.exit.y);
	printf("\n");
}

void	log_key_event(t_keycode keycode)
{
	log_time();
	printf("\tKey Event:\t");
	switch (keycode)
	{
	case XK_Escape:
		printf("Esc");
		break ;
	case XK_p:
		printf("P");
		break ;
	case XK_w:
		printf("W");
		break ;
	case XK_a:
		printf("A");
		break ;
	case XK_s:
		printf("S");
		break ;
	case XK_d:
		printf("D");
		break ;
	default:
		printf("%d", keycode);
	}
	printf("\n");
}
void	log_loop_event(void)
{
	log_time();
	printf("\tLoop Event\n");
}

void	log_str_lst(const t_list *strs)
{
	while (strs)
	{
		printf("%s\n", (const char *)strs->content);
		strs = strs->next;
	}
}

void	log_char_matrix(const char **matrix, t_dimension size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size.h)
	{
		col = 0;
		while (col < size.w)
		{
			ft_putchar_fd(matrix[row][col], 1);
			col++;
		}
		ft_putchar_fd('\n', 1);
		row++;
	}
}

void	log_pos(t_position pos)
{
	printf("x: %d y: %d", pos.x, pos.y);
}

void	ascii_render(const t_game *game)
{
	t_position	current;
	int row;
	int col;

	row = 0;
	while (row < game->size.h)
	{
		col = 0;
		while (col < game->size.w)
		{
			current = position(col, row);
			if (is_wall(current, game))
				printf("#");
			else if (game->n_collectibles)
			{
				if (is_player(current, game))
					printf("x");
				else if (is_collectible(current, game))
					printf("o");
				else
					printf(" ");
			}
			else
			{
				if (is_player(current, game))
					printf("X");
				else if (is_exit(current, game))
					printf("*");
				else
					printf(" ");
			}
			col++;
		}
		printf("\n");
		row++;
	}
}
