/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:19:20 by jolivare          #+#    #+#             */
/*   Updated: 2024/05/08 11:47:28 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_parent(t_pipe *pipex)
{
	pid_t	current_child;
	int		status;

	close(pipex->tube[0]);
	while (1)
	{
		current_child = waitpid(-1, &status, 0);
		if (current_child <= 0)
			break;
		if (current_child == pipex->last_child)
		{
			if (WEXITSTATUS(status))
				pipex->status = WEXITSTATUS(status);
		}
	}
	if (pipex->here_doc == 1)
		unlink("here_doc");
	exit (status);
}

int main(int argc, char **argv, char **envp)
{
	t_pipe 	pipex;
	int		i;
	pid_t	first_child;
	pid_t	middle_child;
	pid_t	last_child;

	pipex.envp = envp;
	pipex.argc = argc;
	pipex.args = argv;
	
	if (argc < 5)
		args_error();
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		i = 4;
		pipex.here_doc = 1;
		write_here_doc(argv[2], &pipex);
	}
	else
		i = 3;
	if (pipe(pipex.tube) == -1)
		pipe_error();
	first_child = fork();
	if (first_child == -1)
		exit (1);
	if (first_child == 0)
	{
		if (pipex.here_doc == 1)
			make_first_child(&pipex, argv[3], argv[1]);
		else
			make_first_child(&pipex, argv[2], argv[1]);	
	}
	close(pipex.tube[WRITE]);
	while (i < argc - 2)
	{
		// pipex.tube[0] = pipex.new_tube[0];
		// pipex.tube[1] = pipex.new_tube[1];
		if (pipe(pipex.new_tube) == -1)
			pipe_error();
		middle_child = fork();
		if (middle_child == -1)
			exit (1);
		if (middle_child == 0)
			make_mid_childs(&pipex, argv[i]);
		close(pipex.tube[0]);
		pipex.tube[0] = pipex.new_tube[0];
		//close(pipex.tube[1]);
		close(pipex.new_tube[1]);
		i++;
	}
	last_child = fork();
	pipex.last_child = last_child;
	if (last_child == -1)
		exit (1);
	if (last_child == 0)
		make_last_child(&pipex, argv[argc - 2], argv[argc - 1]);
	if (last_child > 0)
		close_parent(&pipex);
	if (pipex.here_doc == 1)
		unlink("here_doc");
	exit(pipex.status);
}
