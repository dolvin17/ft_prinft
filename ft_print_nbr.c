/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:04:25 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/13 17:56:46 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	if (n == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		ft_print_nbr(147483648);
	}
	else if (n < 0)
	{
		ft_print_char('-');
		ft_print_nbr(n * -1);
	}
	else if (n < 10)
		ft_print_char((char)(n + '0'));
	else
	{
		ft_print_nbr(n / 10);
		ft_print_char(n % 10 + '0');
	}
	return (0);
}
