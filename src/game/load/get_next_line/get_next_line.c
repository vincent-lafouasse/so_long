/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:12:19 by poss              #+#    #+#             */
/*   Updated: 2024/05/14 22:24:49 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 512
#endif

char	*get_next_line(int fd)
{
	static t_char_queue	*queue;
	ssize_t				bytes_read;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (char_queue_contains(queue, '\n'))
		return (move_line_from_queue(&queue));
	bytes_read = load_queue(&queue, fd, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		char_queue_clear(&queue);
		return (NULL);
	}
	if (bytes_read == 0 && !queue)
		return (NULL);
	while (bytes_read == BUFFER_SIZE && !char_queue_contains(queue, '\n'))
		bytes_read = load_queue(&queue, fd, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		char_queue_clear(&queue);
		return (NULL);
	}
	return (move_line_from_queue(&queue));
}

char	*move_line_from_queue(t_char_queue **q_ptr)
{
	char		*line;
	const char	*line_start;

	if (!q_ptr)
		return (NULL);
	line = malloc(1 + line_length(*q_ptr));
	if (!line)
	{
		free(line);
		char_queue_clear(q_ptr);
		return (NULL);
	}
	line_start = line;
	while (*q_ptr)
	{
		*line = char_queue_pop_front(q_ptr);
		line++;
		if (*(line - 1) == '\n')
			break ;
	}
	*line = '\0';
	return ((char *)line_start);
}

ssize_t	load_queue(t_char_queue **q_ptr, int fd, size_t buffer_size)
{
	char	*buffer;
	ssize_t	bytes_read;
	ssize_t	i;
	bool	push_status;

	buffer = malloc(buffer_size);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, buffer_size);
	i = 0;
	while (i < bytes_read)
	{
		push_status = char_queue_push_back(q_ptr, buffer[i]);
		if (!push_status)
		{
			bytes_read = -1;
			break ;
		}
		i++;
	}
	free(buffer);
	return (bytes_read);
}

size_t	line_length(const t_char_queue *q)
{
	size_t	len;

	len = 0;
	while (q)
	{
		len++;
		if (q->c == '\n')
			break ;
		q = q->next;
	}
	return (len);
}
