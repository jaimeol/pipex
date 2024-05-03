/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:08:47 by jolivare          #+#    #+#             */
/*   Updated: 2023/11/14 09:32:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(char const *str, ...);
void	ft_putchar_pf(char c, size_t *cont);
void	ft_putstr_pf(char *str, size_t *cont);
void	ft_putnbr_pf(int num, size_t *cont);
void	ft_puthexlow_pf(unsigned long num, size_t *cont);
void	ft_puthexup_pf(unsigned long num, size_t *cont);
void	ft_putunsigned_pf(unsigned int n, size_t *cont);
void	ft_putptr_pf(void *str, size_t *cont);

#endif
