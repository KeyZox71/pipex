/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:13:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/03/28 22:37:50 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"
#include "libft.h"

t_pcmd	split_cmd(char *cmd)
{
	char	**split;
	t_pcmd	cmd;

	split = ft_split(cmd, 32);
}

t_pcmd	*parse_cmd(int ac, char **av)
{
	char	**tmp;

	tmp = av + 1;
	while (*tmp)
	{
		tmp++;
	}
}
