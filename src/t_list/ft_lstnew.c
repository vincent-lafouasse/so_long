/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:50:43 by poss              #+#    #+#             */
/*   Updated: 2024/04/15 14:45:26 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_list.h"

t_list* ft_lstnew(void* content)
{
    t_list* new;

    new = malloc(sizeof(*new));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}
