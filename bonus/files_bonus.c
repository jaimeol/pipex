/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:00:20 by jolivare          #+#    #+#             */
/*   Updated: 2024/05/09 11:49:31 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_file(char *infile, t_pipe *pipex)
{
	pipex->infile_fd = open(infile, O_RDONLY);
	if (pipex->infile_fd < 0)
		return (1);
	return (0);
}

int	create_file(char *outfile, t_pipe *pipex)
{
	pipex->outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd == -1)
		return (1);
	return (0);
}

void	open_aux_file(t_pipe *pipex)
{	
	pipex->aux_file_fd = open("here_doc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (pipex->aux_file_fd < 0)
		exit (1);
}
