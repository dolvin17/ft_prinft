/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:29:26 by ghuertas          #+#    #+#             */
/*   Updated: 2022/04/21 05:43:36 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_base(int n, char *base)
{
	int	bhex;

	bhex = ft_strlen(base);
	if (n == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		ft_putnbr_base(147483648, base);
	}
	else if (n < 0)
	{
		ft_print_char('-');
		ft_putnbr_base(n * -1, base);
	}
	else if (n < bhex)
		ft_print_char(base[n]);
	else
	{
		ft_putnbr_base(n / bhex, base);
		ft_print_char(base[n % bhex]);
	}
}
/*
int	main(void)
{
	const char	typhex[] = "0123456789abcdef";

	printf("%s\n", ft_putnbr_base(2345, &typex));
	return (0)
}*/