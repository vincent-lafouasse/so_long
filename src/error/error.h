/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:30:02 by vlafouas          #+#    #+#             */
/*   Updated: 2024/06/13 17:30:19 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdbool.h>

void	die(const char *error_message);
void	ft_assert(bool assertion, const char *message);

#endif
