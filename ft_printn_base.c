/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printn_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:29:26 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/15 14:05:45 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t ft_num_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
		{
			(n /= 10);
			len++;
		}
		return (len);
}
int	ft_printn_base(int n, char *base)
{
	int	bhex;

	bhex = ft_strlenv2(base);
	if (n == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		ft_printn_base(147483648, base);
	}
	else if (n < 0)
	{
		ft_print_char('-');
		ft_printn_base(n * -1, base);
	}
	else if (n < bhex)
		ft_print_char(base[n]);
	else
	{
		ft_printn_base(n / bhex, base);
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
