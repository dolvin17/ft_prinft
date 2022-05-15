/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnu_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:25:17 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/15 20:25:39 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_num_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		(n /= 10);
		len++;
	}
	return (len);
}

int	ft_printnu_base(unsigned int n, char *base)
{
	unsigned int	bhex;

	bhex = ft_strlenv2(base);
	if (n == 2147483648)
	{
		ft_print_char('2');
		ft_printn_base(147483648, base);
	}
	else if (n < bhex)
		ft_print_char(base[n]);
	else
	{
		ft_printnu_base(n / bhex, base);
		ft_print_char(base[n % bhex]);
	}
	return (ft_num_len(n));
}
/*
int	main(void)
{
	const char	typhex[] = "0123456789";

	printf("%u\n", printn_base(2147483647, &typex));
	return (0)
}*/