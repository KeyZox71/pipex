/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:32:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/08 14:18:42 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	getpath(t_pipex *pipex)
{
	char	**env;

	env = pipex->env;
	while (*env)
	{
		if (!ft_strncmp(*env, "PATH=", 5))
		{
			pipex->path = ft_split((*env) + 5, ':');
			return ;
		}
		env++;
	}
	pipex->path = NULL;
}
