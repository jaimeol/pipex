/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:28:33 by jolivare          #+#    #+#             */
/*   Updated: 2023/11/14 09:55:25 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *str, size_t *cont)
{
	if (str == NULL)
	{
		ft_putstr_pf("(null)", cont);
		return ;
	}
	while (*str)
	{
		ft_putchar_pf(*str, cont);
		str++;
	}
}
