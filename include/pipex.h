/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:14:06 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/03 14:24:09 by adjoly           ###   ########.fr       */
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
	int		infile;
	int		outfile;
}	t_pipex;

void	ft_senderror(t_pipex *pipex, char *msg);

#endif
