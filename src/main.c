/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:03:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/07 11:03:19 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>

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

void	check_empty_args(char **av)
{
	char	**tmp;
	char	*tmp_av;

	tmp = av;
	tmp++;
	while (*tmp)
	{
		tmp_av = *tmp;
		if (!*tmp_av)
			ft_senderror(NULL, "You have empty argument");
		while (*tmp_av)
		{
			if (*tmp_av != 32)
				break ;
			tmp_av++;
		}
		if (!*tmp_av)
			ft_senderror(NULL, "You have empty argument");
		tmp++;
	}
}

void	ft_senderror(t_pipex *pipex, char *msg)
{
	(void)pipex;
	ft_putendl_fd(msg, STDERR_FILENO);
	if (!pipex)
		exit(EXIT_FAILURE);
	if (pipex->path)
		ft_freearr(pipex->path);
	if (pipex->cmd)
		free_pcmd(pipex->cmd);
	free(pipex);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (ac != 5)
		ft_senderror(pipex, "Error : Invalid number of args");
	check_empty_args(av);
	pipex->infile = open(av[1], O_RDONLY);
	dup2(pipex->infile, STDIN_FILENO);
	pipex->outfile = av[ac - 1];
	pipex->cmd = parse_cmd(ac - 3, av);
	pipex->env = env;
	getpath(pipex);
	if (pipex->path == NULL)
		ft_senderror(pipex, "Error : Can't find path");
	ft_strlcpy(*(pipex->path), *(pipex->path) + 5, \
			ft_strlen(*(pipex->path) + 5) + 1);
	get_arrcmd_path(pipex);
	exec_pipe(pipex);
	ft_freearr(pipex->path);
	free_pcmd(pipex->cmd);
	free(pipex);
	return (EXIT_SUCCESS);
}
