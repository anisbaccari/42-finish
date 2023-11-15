/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:47:21 by abaccari          #+#    #+#             */
/*   Updated: 2023/11/15 12:33:30 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/includes/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef EXIT_CODE
#  define EXIT_CODE 2
# endif
# define SUCCES 1
# define FAIL -1
# define CNF 127

enum
{
	INPUT_ERROR = 0,
	OUTPUT_ERROR = 1,
	ARGC_ERROR = 2,
	CMD_ERROR = 3,
	PIPE_ERROR = 4,
	FORK_ERROR = 5
};

void	parent(int fd[2], char **argv, char **env);
void	child(int fd[2], char **argv, char **env);
void	exec(char *argv, char **env);
char	*get_cmd(char *cmd, char **env);
void	error_arg(char *msg);
void	ft_error(char *cmd, char *msg, char **path);
void	ft_freedom(char **str);
void	ft_exit(char *argv, char *msg, char **cmd);

#endif