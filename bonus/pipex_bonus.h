/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:19:55 by jolivare          #+#    #+#             */
/*   Updated: 2024/05/08 12:55:14 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
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
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

typedef struct s_pipe
{
	int		tube[2];
	int		new_tube[2];
	int		infile_fd;
	int		outfile_fd;
	int		aux_file_fd;
	int		here_doc;
	int		argc;
	int		arg_i;
	int		status;
	char	**envp;
	char	**args;
	char	*path;
	pid_t	last_child;
}	t_pipe;

char	*get_next_line(int fd);

int		create_aux_file(char *aux_file, t_pipe *pipex);
int		create_file(char *outfile, t_pipe *pipex);
int		open_file(char *infile, t_pipe *pipex);

void	write_here_doc(char	*limiter, t_pipe *pipex);

void	free_path(char **paths);
char	**get_path(t_pipe *pipe);
int		check_path(char *paths, t_pipe *pipe);
int		get_values(char *command, t_pipe *pipe);

void	child_error(t_pipe *pipe);
void	args_error(void);
void	pipe_error(void);
void	here_doc_error(void);

void	make_first_child(t_pipe *pipe, char *arg, char *infile);
void	make_mid_childs(t_pipe *pipe, char *arg);
void	make_last_child(t_pipe *pipe, char *arg, char *outfile);
void	close_parent(t_pipe *pipex);

void	do_fork(t_pipe *pipex);
void	first_fork(t_pipe *pipex);
void	middle_fork(t_pipe *pipex);
void	last_fork(t_pipe *pipex);

#endif