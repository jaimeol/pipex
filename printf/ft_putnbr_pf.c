/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:34:52 by jolivare          #+#    #+#             */
/*   Updated: 2023/11/14 09:36:05 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int num, size_t *cont)
{
	if (num == -2147483648)
	{
		ft_putnbr_pf((num / 10), cont);
		ft_putchar_pf('8', cont);
	}
	else if (num < 0)
	{
		ft_putchar_pf('-', cont);
		ft_putnbr_pf(-num, cont);
	}
	else
	{
		if (num > 9)
			ft_putnbr_pf((num / 10), cont);
		ft_putchar_pf(('0' + num % 10), cont);
	}
}
