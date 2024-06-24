/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:19:20 by jolivare          #+#    #+#             */
/*   Updated: 2024/06/13 17:17:06 by jolivare         ###   ########.fr       */
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
			break ;
		if (current_child == pipex->last_child)
			pipex->status = WEXITSTATUS(status);
	}
	if (pipex->here_doc == 1)
		unlink("here_doc");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	pipex.envp = envp;
	pipex.argc = argc;
	pipex.args = argv;
	if (argc < 5)
		args_error();
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		if (argc < 6)
			here_doc_error();
		pipex.arg_i = 4;
		pipex.here_doc = 1;
		write_here_doc(argv[2], &pipex);
	}
	else
	{
		pipex.here_doc = 0;
		pipex.arg_i = 3;
	}
	do_fork(&pipex);
	if (pipex.last_child > 0)
		close_parent(&pipex);
	exit(pipex.status);
}
