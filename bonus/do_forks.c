/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:42:43 by jolivare          #+#    #+#             */
/*   Updated: 2024/06/13 17:00:29 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_fork(t_pipe *pipex)
{
	pid_t	first_child;

	if (pipe(pipex->tube) == -1)
		pipe_error();
	first_child = fork();
	if (first_child == -1)
		exit (1);
	if (first_child == 0)
	{
		if (pipex->here_doc == 1)
			make_first_child(pipex, pipex->args[3], pipex->args[1]);
		else
			make_first_child(pipex, pipex->args[2], pipex->args[1]);
	}
}

void	middle_fork(t_pipe *pipex)
{
	pid_t	middle_child;

	close(pipex->tube[WRITE]);
	while (pipex->arg_i < pipex->argc - 2)
	{
		if (pipe(pipex->new_tube) == -1)
			pipe_error();
		middle_child = fork();
		if (middle_child == -1)
			exit (1);
		if (middle_child == 0)
			make_mid_childs(pipex, pipex->args[pipex->arg_i]);
		close(pipex->tube[0]);
		pipex->tube[0] = pipex->new_tube[0];
		close(pipex->new_tube[1]);
		pipex->arg_i++;
	}
}

void	last_fork(t_pipe *pipex)
{
	pid_t	last_child;

	last_child = fork();
	pipex->last_child = last_child;
	if (last_child == -1)
		exit (1);
	if (last_child == 0)
		make_last_child(pipex, pipex->args[pipex->argc - 2],
			pipex->args[pipex->argc - 1]);
}

void	do_fork(t_pipe *pipex)
{
	first_fork(pipex);
	middle_fork(pipex);
	last_fork(pipex);
}
