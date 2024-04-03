/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:36:42 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/03 16:27:03 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	char *cmd[] = {"sleep", "5", 0};
	char *path = "/bin/sleep";
	char *cmd2[] = {"sleep", "5", 0};
	char *path2 = "/bin/sleep";
	int fd[2];
	if (pipe(fd) == -1)
		return(1);
	int	pid = fork();
	if (!pid)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(path, cmd, NULL);
	}
	close(fd[1]);
	int pid2 = fork();
	if (!pid2)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execve(path2, cmd2, NULL);
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}
