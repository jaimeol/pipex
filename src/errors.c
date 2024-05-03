/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:35:50 by jolivare          #+#    #+#             */
/*   Updated: 2024/04/29 14:43:14 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_error(void)
{
	ft_printf("Pipe error\n");
	exit(1);
}

void	args_error(void)
{
	ft_printf("Invalid args: [infile cmd1 cmd2 outfile]\n");
	exit (1);
}
