/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:47:45 by poss              #+#    #+#             */
/*   Updated: 2024/04/17 15:24:49 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "t_list.h"

t_list* ft_lstlast(t_list* lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
    {
        lst = lst->next;
    }
    return (lst);
}
