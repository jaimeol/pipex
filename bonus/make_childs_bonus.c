/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_childs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:59:36 by jolivare          #+#    #+#             */
/*   Updated: 2024/06/13 17:00:37 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_first_child(t_pipe *pipe, char *arg, char *infile)
{
	if (open_file(infile, pipe) == 1)
		child_error(pipe);
	if (get_values(arg, pipe) == 1)
		child_error(pipe);
	dup2(pipe->tube[WRITE], STDOUT_FILENO);
	dup2(pipe->infile_fd, STDIN_FILENO);
	close(pipe->tube[READ]);
	close(pipe->tube[WRITE]);
	close(pipe->infile_fd);
	execve(pipe->path, pipe->args, pipe->envp);
	child_error(pipe);
}

void	make_mid_childs(t_pipe *pipe, char *arg)
{
	if (get_values(arg, pipe) == 1)
		child_error(pipe);
	dup2(pipe->tube[READ], STDIN_FILENO);
	dup2(pipe->new_tube[WRITE], STDOUT_FILENO);
	close (pipe->tube[READ]);
	close(pipe->new_tube[READ]);
	close (pipe->new_tube[WRITE]);
	execve(pipe->path, pipe->args, pipe->envp);
	child_error(pipe);
}

void	make_last_child(t_pipe *pipe, char *arg, char *outfile)
{
	if (create_file (outfile, pipe) == 1)
		child_error(pipe);
	if (get_values(arg, pipe) == 1)
		child_error(pipe);
	dup2(pipe->tube[READ], STDIN_FILENO);
	dup2(pipe->outfile_fd, STDOUT_FILENO);
	close(pipe->tube[READ]);
	close(pipe->tube[WRITE]);
	close(pipe->outfile_fd);
	execve(pipe->path, pipe->args, pipe->envp);
	child_error(pipe);
}
