/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:14:06 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/07 17:02:48 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "parsing.h"
# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pipex
{
	t_pcmd	*cmd;
	char	**path;
	char	**env;
	int		infile;
	char	*outfile;
}	t_pipex;

void	ft_senderror(t_pipex *pipex, char *msg);
void	getpath(t_pipex *pipex);
void	get_arrcmd_path(t_pipex *pipex);
void	exec_pipe(t_pipex *pipex);
void	ft_senderror(t_pipex *pipex, char *msg);
void	ft_senderror_file(t_pipex *pipex, char *msg);
void	free_pcmd(t_pcmd *cmd);

#endif
