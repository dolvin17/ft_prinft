/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:15:53 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/15 20:07:20 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_num_len(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		(n /= 16);
		len++;
	}
	return (len);
}

int	ft_print_hex(unsigned long n, char *base)
{
	unsigned int	bhex;

	bhex = ft_strlenv2(base);
	if (n == 9223372036854775808UL)
	{
		ft_print_hex(9223372036854775808UL, base);
	}
	else if (n < bhex)
		ft_print_char(base[n]);
	else
	{
		ft_print_hex(n / bhex, base);
		ft_print_char(base[n % bhex]);
	}
	return (ft_num_len(n));
}
/*
int	main(void)
{
	const char	typhex[] = "0123456789abcdef";

	printf("%s\n", printn_base(2345, &typex));
	return (0)
}*/
