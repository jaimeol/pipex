/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:28:09 by jolivare          #+#    #+#             */
/*   Updated: 2023/11/14 11:30:11 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned_pf(unsigned int n, size_t *cont)
{
	char	str;

	if (n >= 10)
	{
		ft_putunsigned_pf((n / 10), cont);
	}
	str = n % 10 + '0';
	write(1, &str, 1);
	(*cont)++;
}
