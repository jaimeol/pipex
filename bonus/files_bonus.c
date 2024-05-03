/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:00:20 by jolivare          #+#    #+#             */
/*   Updated: 2024/05/03 14:00:33 by jolivare         ###   ########.fr       */
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
