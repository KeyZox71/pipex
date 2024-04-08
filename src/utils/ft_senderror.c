/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_senderror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:59:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/07 17:14:06 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

void	free_pcmd(t_pcmd *cmd)
{
	t_pcmd	*tmp;

	tmp = cmd;
	while (tmp && tmp->cmd)
	{
		free(tmp->cmd);
		ft_freearr(tmp->option);
		tmp++;
	}
	free(cmd);
}

void	ft_senderror(t_pipex *pipex, char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (!pipex)
		exit(EXIT_FAILURE);
	if (pipex->infile > -1)
		close(pipex->infile);
	if (pipex->cmd)
		free_pcmd(pipex->cmd);
	if (pipex->path)
		ft_freearr(pipex->path);
	free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_senderror_file(t_pipex *pipex, char *msg)
{
	int	out;

	ft_putendl_fd(msg, STDERR_FILENO);
	if (pipex->infile > -1)
		close(pipex->infile);
	out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out == -1)
	{
		free(pipex);
		exit(EXIT_FAILURE);
	}
	close(out);
	free(pipex);
	exit(EXIT_FAILURE);
}
