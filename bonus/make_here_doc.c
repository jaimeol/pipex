/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:35:27 by jolivare          #+#    #+#             */
/*   Updated: 2024/05/08 12:52:33 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	write_here_doc(char *limiter, t_pipe *pipex)
{
	int		aux_file;
	char	*text;

	aux_file = open("here_doc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (aux_file < 0)
		exit (1);
	while (1)
	{
		write (1, "here_doc>", 9);
		text = get_next_line(0);
		if (text == NULL)
		{
			close (aux_file);
			exit (1);
		}
		if (!ft_strncmp(limiter, text, ft_strlen(text) - 1))
			break ;
		write(aux_file, text, ft_strlen(text));
		free (text);
	}
	free (text);
	close (aux_file);
	pipex->infile_fd = open("here_doc", O_RDONLY);
	if (pipex->infile_fd < 0)
		exit (1);
}
