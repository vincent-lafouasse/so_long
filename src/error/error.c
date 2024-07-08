/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:30:46 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 15:29:41 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft/ft_io.h"
#include <stdlib.h>
#include <unistd.h>

void	die(const char *error_message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_message, STDERR_FILENO);
	exit(1);
}

void	ft_assert(bool assertion, const char *message)
{
	if (assertion)
		return ;
	die(message);
}
