/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:28:32 by jolivare          #+#    #+#             */
/*   Updated: 2024/05/03 14:27:30 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	child_error(t_pipe *pipe)
{
	perror("error");
	close(pipe->tube[0]);
	close(pipe->tube[1]);
	close(pipe->infile_fd);
	close(pipe->outfile_fd);
	exit(1);
}
