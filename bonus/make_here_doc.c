/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:35:27 by jolivare          #+#    #+#             */
/*   Updated: 2024/06/17 10:28:13 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	write_here_doc(char *limiter, t_pipe *pipex)
{
	char	*text;
	char	*complete_limiter;

	open_aux_file(pipex);
	complete_limiter = ft_strjoin(limiter, "\n");
	while (1)
	{
		write (1, "here_doc>", 9);
		text = get_next_line(0);
		if (text == NULL)
			break ;
		if (!ft_strcmp(complete_limiter, text))
			break ;
		write(pipex->aux_file_fd, text, ft_strlen(text));
		free (text);
	}
	if (text)
		free (text);
	close (pipex->aux_file_fd);
	free(complete_limiter);
	pipex->infile_fd = open("here_doc", O_RDONLY);
	if (pipex->infile_fd < 0)
		exit (1);
}
