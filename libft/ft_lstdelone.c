/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:40:49 by jolivare          #+#    #+#             */
/*   Updated: 2024/05/02 17:31:27 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(del)(lst -> content);
	free(lst);
	lst  = NULL;
}
