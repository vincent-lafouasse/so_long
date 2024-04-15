/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_internals.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:21:39 by vlafouas          #+#    #+#             */
/*   Updated: 2024/04/15 14:23:34 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_INTERNALS_H
#define GET_NEXT_LINE_INTERNALS_H

# include <stdbool.h>
# include <sys/types.h>

/** @struct t_char_queue
 *  @brief A Simple Queue of characters
 *
 * It provides the following functions with the usual semantics:
 * `Self new()`
 * `bool push_back(char)`
 * `char pop_front()`
 * `bool contains(char)`
 * `void clear()`
 *
 * except that `push_back` returns a boolean flag
 */
typedef struct s_char_queue
{
	char				c;
	struct s_char_queue	*next;
}						t_char_queue;
t_char_queue			*char_queue_new(char c);
bool					char_queue_push_back(t_char_queue **q_ptr, char c);
char					char_queue_pop_front(t_char_queue **q_ptr);
bool					char_queue_contains(const t_char_queue *q, char c);
void					char_queue_clear(t_char_queue **q);

/** @fn char *move_line_from_queue(t_char_queue **q)
 *  @brief Move the next line from the queue to a heap-allocated string
 *
 *  The line is ended either by a newline or by the end of the queue. The
 *  newline is included
 */

/** @fn size_t line_length(const t_char_queue* pop)
 *  @brief Compute the length of the line in the queue/buffer
 *
 *  For the definition of what a line is:
 *  @see char *move_line_from_queue(t_char_queue **q)
 */

/** @fn ssize_t load_queue(t_char_queue **q, int fd, size_t buffer_size)
 *  @brief Loads a buffer into the queue
 *
 *  A wrapper for `read` that loads the bytes into a queue rather than an array
 *  @return the return value of `read`
 */
char					*move_line_from_queue(t_char_queue **q_ptr);
size_t					line_length(const t_char_queue *q);
ssize_t					load_queue(t_char_queue **q_ptr, int fd,
							size_t buffer_size);

#endif
