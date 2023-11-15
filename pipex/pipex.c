/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:44:22 by abaccari          #+#    #+#             */
/*   Updated: 2023/11/15 12:55:42 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	*get_cmd(char *cmd, char **env)
{
	char	**e_path;
	char	*c_path;
	char	*path;
	int		i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH=", 5))
		i++;
	e_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (e_path[i++])
	{
		path = ft_strjoin(e_path[i], "/");
		c_path = ft_strjoin(path, cmd);
		if (path)
			free(path);
		if (access(c_path, F_OK) == 0)
		{
			ft_freedom(e_path);
			return (c_path);
		}
		free(c_path);
	}
	ft_freedom(e_path);
	return (NULL);
}

void	exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = get_cmd(cmd[0], env);
	if (!path || cmd[0] == NULL)
	{
		if (path)
			free(path);
		ft_exit(argv, "command not found", cmd);
	}
	if (execve(path, cmd, env) == -1)
	{
		free(path);
		ft_exit(argv, strerror(errno), cmd);
	}
	exit(0);
}

void	child(int fd[2], char **argv, char **env)
{
	int	inputfd;

	close(fd[0]);
	inputfd = open(argv[1], O_RDONLY, 0777);
	if (inputfd < 0)
	{
		ft_exit(argv[1], strerror(errno), NULL);
		close(fd[1]);
	}
	dup2(inputfd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	exec(argv[2], env);
	close(inputfd);
}

void	parent(int fd[2], char **argv, char **env)
{
	int	outputfd;

	close(fd[1]);
	outputfd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (outputfd < 0)
	{
		ft_error(argv[4], strerror(errno), NULL);
		close(fd[0]);
		exit(0);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outputfd, STDOUT_FILENO);
	close(fd[0]);
	exec(argv[3], env);
	close(outputfd);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pd;

	if (argc == 5)
	{
		if (pipe(fd) < 0)
			exit(FAIL);
		pd = fork();
		if (pd < 0)
			exit(FAIL);
		else if (pd == 0)
			child(fd, argv, env);
		else
			parent(fd, argv, env);
		waitpid(pd, NULL, 0);
	}
	return (0);
}
