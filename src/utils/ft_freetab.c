/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:34:09 by adjoly            #+#    #+#             */
/*   Updated: 2024/03/30 11:58:39 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_freearr(char	**arr)
{
	char	**tmp;

	tmp = arr;
	while(tmp && *tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(arr);
}
