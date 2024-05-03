/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:49:40 by jolivare          #+#    #+#             */
/*   Updated: 2024/04/10 17:13:13 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <unistd.h>
# define WRITE 1
# define READ 0

typedef struct s_pipe
{
	int		tube[2];
	int		infile_fd;
	int		outfile_fd;
	char	**envp;
	char	**args;
	char	*path;
}	t_pipe;

int		open_file(char *infile, t_pipe *pipe);
int		create_file(char *outfile, t_pipe *pipe);
void	child_error(t_pipe *pipe);

void	free_path(char **paths);
char	**get_path(t_pipe *pipe);
int		check_path(char *paths, t_pipe *pipe);
int		get_values(char *command, t_pipe *pipe);

void	make_first_child(t_pipe *pipe, char *arg, char *infile);
void	make_second_child(t_pipe *pipe, char *arg, char *outfile);
int		close_parent(t_pipe *pipe, int child_1, int child_2);

void	args_error(void);
void	pipe_error(void);

#endif