/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:29:06 by jolivare          #+#    #+#             */
/*   Updated: 2023/11/14 09:11:45 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexup_pf(unsigned long num, size_t *cont)
{
	char	*hexbase;

	hexbase = "0123456789ABCDEF";
	if (num < 16)
		ft_putchar_pf(*(hexbase + num), cont);
	else
	{
		ft_puthexup_pf((num / 16), cont);
		ft_puthexup_pf((num % 16), cont);
	}
}
