/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:32:14 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/12 20:00:35 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static size_t	strings(char *s)
{
	if (!s)
		return (ft_print_str("(null)"), 6);
	ft_print_str(s);
	return (ft_strlenv2(s));
}
*/
int	keyholder(char *format, ...)
{
	int		ptr;
	va_list	holder;

	ptr = 0;
	if (*format == 'd' || *format == 'i')
		ptr += ft_printn_base(va_arg(holder, int), "0123456789");
	if (*format == 'u')
		ptr = ptr + ft_printn_base(va_arg(holder, unsigned int), "0123456789");
	if (*format == 'X')
		ptr = ptr + ft_printn_base(va_arg(holder, int), "0123456789ABCDEF");
	if (*format == 'x')
		ptr = ptr + write(1, "0x", 2)
			+ ft_printn_base(va_arg(holder, unsigned int), "0123456789abcdef");
	if (*format == 'p')
		ptr = ptr + ft_printn_base(va_arg(holder, size_t), "0123456789abcdef");
	if (*format == 'c')
		ptr = ptr + ft_print_char(va_arg(holder, int));
	if (*format == 's')
		ptr = ptr + ft_print_str(va_arg(holder, char *));
	if (*format == '%')
		ptr = ptr + write(1, "%", 1);
	return (0);
}

int	ft_printf(char const *format, ...)
{	
	va_list	key_list;
	int		printptr;
	size_t	i;
	char	*c_format;

	va_start(key_list, format);
	c_format = (char *)format;
	i = 0;
	printptr = 0;
	while (*c_format)
	{
		if (c_format[i] == '%')
		{
			printptr = printptr + keyholder(va_arg(key_list, char *));
			i++;
		}
		else
		{
			printptr = printptr + keyholder(va_arg(key_list, char *));
			i++;
		}
	}
	va_end(key_list);
	return (printptr);
}
/*
int	main(void)
{
	char	*s;

	ft_printf(El numero es: "%d\n", 4);
	ft_printf(El numero es: "%s\n", 4);
	ft_printf(El numero es: "%c\n", 4);
	ft_printf(El numero es: "%i\n", 4);
	ft_printf(El numero es: "%u\n", 4);
	ft_printf(El numero es: "%X\n", 4);
	ft_printf(El numero es: "%x\n", 4);
	ft_printf(El numero es: "%p\n", 4);


	return (0);
}*/
