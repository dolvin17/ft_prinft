/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printn_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:29:26 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/12 20:23:30 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	printn_base(int n, char *base)
{
	int	bhex;

	bhex = ft_strlenv2(base);
	if (n == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		printn_base(147483648, base);
	}
	else if (n < 0)
	{
		ft_print_char('-');
		printn_base(n * -1, base);
	}
	else if (n < bhex)
		ft_print_char(base[n]);
	else
	{
		printn_base(n / bhex, base);
		ft_print_char(base[n % bhex]);
	}
	return (0);
}
/*
int	main(void)
{
	const char	typhex[] = "0123456789abcdef";

	printf("%s\n", printn_base(2345, &typex));
	return (0)
}*/
