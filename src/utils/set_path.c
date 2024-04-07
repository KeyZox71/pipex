/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:31:15 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/06 17:30:03 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_cmd(char *path, char *cmd)
{
	char	*str;
	char	*ret;

	str = ft_strjoin(path, "/");
	ret = ft_strjoin(str, cmd);
	free(str);
	return (ret);
}

char	*get_cmd_path(t_pipex *pipex, char *cmd)
{
	char	**path;
	char	*tmp;

	path = pipex->path;
	while (*path)
	{
		tmp = join_cmd(*path, cmd);
		if (access(tmp, X_OK) == 0)
		{
			free(cmd);
			cmd = ft_strdup(tmp);
			free (tmp);
			return (cmd);
		}
		free(tmp);
		path++;
	}
	return (NULL);
}

void	get_arrcmd_path(t_pipex *pipex)
{
	t_pcmd	*cmd;

	cmd = pipex->cmd;
	while ((*cmd).option)
	{
		(*cmd).cmd = get_cmd_path(pipex, (*cmd).cmd);
		cmd++;
	}
}
