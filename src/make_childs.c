/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:49:26 by jolivare          #+#    #+#             */
/*   Updated: 2024/04/09 18:39:18 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *infile, t_pipe *pipe)
{
	pipe->infile_fd = open(infile, O_RDONLY);
	if (pipe->infile_fd < 0)
		return (1);
	return (0);
}

int	create_file(char *outfile, t_pipe *pipe)
{
	pipe->outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe->outfile_fd == -1)
		return (1);
	return (0);
}

void	child_error(t_pipe *pipe)
{
	perror("error");
	close(pipe->tube[0]);
	close(pipe->tube[1]);
	close(pipe->infile_fd);
	close(pipe->outfile_fd);
	exit(127);
}

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

void	make_second_child(t_pipe *pipe, char *arg, char *outfile)
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
