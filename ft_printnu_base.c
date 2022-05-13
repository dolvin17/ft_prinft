/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnu_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:25:17 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/13 20:26:25 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnu_base(unsigned int n, char *base)
{
	unsigned int	bhex;

	bhex = ft_strlenv2(base);
	if (n == 2147483647)
	{
		ft_printnu_base(2147483647, base);
	}
	else if (n < bhex)
		ft_print_char(base[n]);
	else
	{
		ft_printnu_base(n / bhex, base);
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