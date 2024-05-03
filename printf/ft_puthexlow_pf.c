/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:24:13 by jolivare          #+#    #+#             */
/*   Updated: 2023/11/14 09:09:42 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexlow_pf(unsigned long num, size_t *cont)
{
	char	*hexbase;

	hexbase = "0123456789abcdef";
	if (num < 16)
		ft_putchar_pf(*(hexbase + num), cont);
	else
	{
		ft_puthexlow_pf((num / 16), cont);
		ft_puthexlow_pf((num % 16), cont);
	}
}
