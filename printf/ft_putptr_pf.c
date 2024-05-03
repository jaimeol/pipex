/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:34:00 by jolivare          #+#    #+#             */
/*   Updated: 2023/11/14 09:10:04 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_pf(void *str, size_t *cont)
{
	unsigned long	ptr;

	ptr = (unsigned long)str;
	if (!ptr)
	{
		ft_putstr_pf("0x0", cont);
		return ;
	}
	ft_putstr_pf("0x", cont);
	ft_puthexlow_pf(ptr, cont);
}
