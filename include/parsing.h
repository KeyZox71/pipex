/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:54:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/03/29 10:41:40 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_pcmd
{
	char	*cmd;
	char	**option;
}	t_pcmd;

void	ft_freearr(char	**arr);
t_pcmd	split_cmd(char *cmd_av);
t_pcmd	*parse_cmd(int ac, char **av);

#endif
