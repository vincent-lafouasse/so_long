/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:10:23 by poss              #+#    #+#             */
/*   Updated: 2024/07/08 14:25:56 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/error.h"
#include "get_next_line/get_next_line.h"
#include "libft/string.h"
#include "libft/t_list.h"
#include "load_internals.h"
#include "t_map.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static t_list		*load_lines_in_lst(const char *map_path);
static t_map		move_str_list_to_map(t_list **lst_p);
static t_dimension	get_map_size(const t_list *map_lst);

t_map	load_map(const char *path)
{
	t_list	*lines;
	t_map	map;

	ft_assert(str_ends_with(path, ".ber"),
		"Invalid map name, map name must end in `.ber`");
	lines = load_lines_in_lst(path);
	ft_assert(lines != NULL, "Failed to read lines from configuration file");
	map = move_str_list_to_map(&lines);
	if (map.data == NULL)
	{
		ft_lstclear(&lines, &free);
		die("Failed to create char** map");
	}
	return (map);
}

static t_list	*load_lines_in_lst(const char *map_path)
{
	int		fd;
	t_list	*lines;
	t_list	*current_node;
	char	*line;

	fd = open(map_path, O_RDONLY);
	lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		trim_trailing_newline(line);
		current_node = ft_lstnew(line);
		if (current_node == NULL)
		{
			ft_lstclear(&lines, &free);
			return (NULL);
		}
		ft_lstadd_front(&lines, current_node);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static t_map	move_str_list_to_map(t_list **lst_p)
{
	t_map	map;
	t_list	*current;
	int		row;

	if (!lst_p)
		return ((t_map){.data = NULL});
	current = *lst_p;
	map.size = get_map_size(*lst_p);
	if (map.size.h < 2 || map.size.w < 2)
	{
		ft_lstclear(lst_p, &free);
		die("map has invalid shape\n");
	}
	map.data = malloc(sizeof(char *) * map.size.h);
	if (!map.data)
		return (map);
	row = map.size.h - 1;
	while (row >= 0 && current)
	{
		map.data[row] = (current)->content;
		row--;
		current = (current)->next;
	}
	return (map);
}

static t_dimension	get_map_size(const t_list *map_lst)
{
	t_dimension	size;

	if (!map_lst)
		return ((t_dimension){.w = 0, .h = 0});
	size.w = ft_strlen(map_lst->content);
	size.h = 1;
	map_lst = map_lst->next;
	while (map_lst)
	{
		if (ft_strlen(map_lst->content) != (size_t)size.w)
			return ((t_dimension){.w = 0, .h = 0});
		size.h++;
		map_lst = map_lst->next;
	}
	return (size);
}
