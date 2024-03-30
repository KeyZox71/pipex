/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:13:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/03/30 12:01:17 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

t_pcmd	split_cmd(char *cmd_av)
{
	char	**split;
	char	**tmp_split;
	t_pcmd	cmd;

	split = ft_split(cmd_av, 32);
	tmp_split = split;
	cmd.cmd = *tmp_split;
	tmp_split++;
	cmd.option = tmp_split;
	return (cmd);
}

t_pcmd	*parse_cmd(int ac, char **av)
{
	char	**tmp;
	t_pcmd	*cmd_arr;
	t_pcmd	*cmd_tmp;
	
	(void)ac;
	cmd_arr = ft_calloc(10000, 1);
	cmd_tmp = cmd_arr;
	tmp = av + 2;
	while (*tmp)
	{
		*cmd_tmp = split_cmd(*tmp);
		cmd_tmp++;
		tmp++;
	}
	return (cmd_arr);
}
