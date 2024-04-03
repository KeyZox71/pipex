/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:13:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/03 14:20:56 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

size_t	ft_arrlen(char **arr)
{
	size_t	len;
	char	**tmp;

	tmp = arr;
	len = 0;
	while (*tmp)
	{
		len += ft_strlen(*tmp);
		tmp++;
	}
	return (len);
}

t_pcmd	split_cmd(char *cmd_av)
{
	char	**split;
	char	**tmp_split;
	t_pcmd	cmd;

	split = ft_split(cmd_av, 32);
	tmp_split = split;
	cmd.cmd = ft_strdup(*tmp_split);
	cmd.option = tmp_split;
	return (cmd);
}

t_pcmd	*parse_cmd(int ac, char **av)
{
	char	**tmp;
	int		i;
	t_pcmd	*cmd_arr;
	t_pcmd	*cmd_tmp;
	
	i = 0;
	cmd_arr = ft_calloc(ac + 1, sizeof(t_pcmd));
	cmd_tmp = cmd_arr;
	tmp = av + 2;
	while (i < ac)
	{
		*cmd_tmp = split_cmd(*tmp);
		cmd_tmp++;
		tmp++;
		i++;
	}
	return (cmd_arr);
}
