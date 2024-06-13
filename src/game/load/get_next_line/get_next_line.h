/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:12:34 by poss              #+#    #+#             */
/*   Updated: 2024/04/15 14:23:37 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line_internals.h"

/** @fn char *get_next_line(int fd)
 *  @brief Read and return the next line from a fd.
 *  @param fd The file descriptor to read from, the caller has ownership of it
 *  @return a heap-allocated string containing the line read from the file, or
 * 		`NULL` if there is nothing else to read or an error occurred
 */
char	*get_next_line(int fd);

#endif
