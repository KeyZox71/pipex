/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:03:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/02 11:08:15 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

int	main(int ac, char **av)
{
	t_pcmd	*cmd;
	t_pcmd	*tmp;
	char	**option_tmp;

	cmd = parse_cmd(ac, av + 2);
	tmp = cmd;
	while (tmp && (*tmp).cmd)
	{
		ft_printf("cmd : %s\n", (*tmp).cmd);
		option_tmp = (*tmp).option;
		while (*option_tmp)
		{
			ft_printf("%s\n", *option_tmp);
			option_tmp++;
		}
		tmp++;
	}
	tmp = cmd;
	while (tmp && (*tmp).cmd)
	{
		if (tmp->option)
			ft_freearr(tmp->option);
		free(tmp->cmd);
		tmp++;
	}
	free(cmd);
	return (EXIT_SUCCESS);
}
