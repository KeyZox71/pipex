/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:32:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/07 11:01:17 by adjoly           ###   ########.fr       */
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
			pipex->path = ft_split(*env, ':');
			return ;
		}
		env++;
	}
	pipex->path = NULL;
}
