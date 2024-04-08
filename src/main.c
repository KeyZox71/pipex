/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:03:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/08 15:26:06 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "pipex.h"
#include <unistd.h>

void	check_cmd_validity(t_pipex *pipex)
{
	t_pcmd	*cmd;

	cmd = pipex->cmd;
	while (cmd)
	{
		if (access(cmd->cmd, X_OK) != 0)
		{
		//	ft_freearr((*cmd).option);
		//	if (pipex->cmd[1].cmd)
		//	{
		//		ft_freearr(pipex->cmd[1].option);
		//		free(pipex->cmd[1].cmd);
		//	}
			ft_senderror(pipex, "Error: Command not found");
		}	
		cmd++;
	}
}

void	check_empty_args(char **av, t_pipex *pipex)
{
	char	**tmp;
	char	*tmp_av;

	tmp = av;
	tmp++;
	while (*tmp)
	{
		tmp_av = *tmp;
		while (*tmp_av)
		{
			if (*tmp_av != 32)
				break ;
			tmp_av++;
		}
		if (!*tmp_av)
		{
			ft_putendl_fd("You have empty argument", STDERR_FILENO);
			free(pipex);
			exit(EXIT_FAILURE);
		}
		tmp++;
	}
}

void	check_files(int ac, char **av, t_pipex *pipex)
{
	int	out;

	pipex->infile = open(av[1], O_RDONLY);
	pipex->outfile = av[ac - 1];
	if (pipex->infile == -1)
		ft_senderror_file(pipex, "Error: Infile can't be opened");
	dup2(pipex->infile, STDIN_FILENO);
	out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out < 0)
		ft_senderror_file(pipex, "Error: Outfile can't be opened");
	close(out);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (ac != 5)
	{
		free(pipex);
		ft_putendl_fd("Error : Invalid number of args", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	check_empty_args(av, pipex);
	check_files(ac, av, pipex);
	pipex->cmd = parse_cmd(ac - 3, av);
	pipex->env = env;
	getpath(pipex);
	if (pipex->path)
		get_arrcmd_path(pipex);
	else
		check_cmd_validity(pipex);
	exec_pipe(pipex);
	ft_freearr(pipex->path);
	free_pcmd(pipex->cmd);
	free(pipex);
	return (EXIT_SUCCESS);
}
