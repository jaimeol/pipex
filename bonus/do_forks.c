/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:42:43 by jolivare          #+#    #+#             */
/*   Updated: 2024/05/03 13:42:10 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	middle_fork(t_pipe *pipex)
{
	pid_t	middle_child;
	int		index;

	if (pipex->here_doc == 1)
		index = 4;
	else
		index = 3;
	while (index < pipex->argc - 2)
	{
		pipex->tube[0] = pipex->new_tube[0];
		pipex->tube[1] = pipex->new_tube[1];
		if (pipe(pipex->new_tube) == -1)
			pipe_error();
		middle_child = fork();
		if (middle_child == -1)
			exit (1);
		if (middle_child == 0)
			make_mid_childs(pipex, pipex->args[index]);
		close(pipex->tube[1]);
		close(pipex->new_tube[1]);
		index++;
	}
}