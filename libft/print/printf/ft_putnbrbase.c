/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:57:44 by adjoly            #+#    #+#             */
/*   Updated: 2024/03/29 12:12:04 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_pputnbrbase(unsigned int n, char *base)
{
	unsigned int	base_len;
	int				len;

	len = 0;
	base_len = (int)ft_strlen(base);
	if (n < base_len)
		len += write(1, &base[n % base_len], 1);
	else
	{
		len += ft_pputnbrbase(n / base_len, base);
		len += write(1, &base[n % base_len], 1);
	}
	return (len);
}

int	ft_putnbrbase_p(unsigned long int n, char *base)
{
	unsigned long int	base_len;
	int					len;

	len = 0;
	base_len = (int)ft_strlen(base);
	if (n < base_len)
		len += write(1, &base[n % base_len], 1);
	else
	{
		len += ft_putnbrbase_p(n / base_len, base);
		len += write(1, &base[n % base_len], 1);
	}
	return (len);
}
