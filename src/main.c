/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:03:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/03 16:30:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
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
	if (pipex->cmd)
		free_pcmd(pipex->cmd);
	free(pipex);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	check_empty_args(av);
	pipex = malloc(sizeof(t_pipex));
	pipex->infile = open(av[1], O_RDONLY);
	pipex->outfile = open(av[ac - 1], O_RDONLY);
	pipex->cmd = parse_cmd(ac - 3, av);
	while (*env)
	{
		ft_putstr_fd(*env, STDOUT_FILENO);
		env++;
	}
	free_pcmd(pipex->cmd);
	free(pipex);
	return (EXIT_SUCCESS);
}

