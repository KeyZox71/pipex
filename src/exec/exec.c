/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:07:27 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/08 15:42:29 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "pipex.h"
#include <sys/wait.h>

pid_t	ft_exec_fst_pipe(t_pipex *pipex, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(pipex->infile);
		close(fd[0]);
		close(fd[1]);
		execve(pipex->cmd[0].cmd, pipex->cmd[0].option, pipex->env);
	}
	return (pid);
}

pid_t	ft_exec_scnd_pipe(t_pipex *pipex, int fd[2])
{
	pid_t	pid;
	int		outfile;

	pid = fork();
	if (!pid)
	{
		outfile = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		close(fd[1]);
		close(pipex->infile);
		execve(pipex->cmd[1].cmd, pipex->cmd[1].option, pipex->env);
	}
	return (pid);
}

void	exec_pipe(t_pipex *pipex)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_senderror(pipex, "Error in opening the pipe");
	pid = ft_exec_fst_pipe(pipex, fd);
	pid2 = ft_exec_scnd_pipe(pipex, fd);
	close(fd[1]);
	close(pipex->infile);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}
