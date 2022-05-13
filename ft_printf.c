/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:32:14 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/13 17:49:13 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	strings(char *s)
{
	if (!s)
		return (ft_print_str("(null)"), 6);
	ft_print_str(s);
	return (ft_strlenv2(s));
}

int	keyholder(va_list *holder, char *format)
{
	int		ptr;

	ptr = 0;
	if (*format == 'd' || *format == 'i')
		ptr += ft_printn_base(va_arg(*holder, int), "0123456789");
	if (*format == 'u')
		ptr = ptr + ft_printn_base(va_arg(*holder, unsigned int), "0123456789");
	if (*format == 'X')
		ptr = ptr + ft_printn_base(va_arg(*holder, int), "0123456789ABCDEF");
	if (*format == 'x')
		ptr = ptr + write(1, "0x", 2)
			+ ft_printn_base(va_arg(*holder, unsigned), "0123456789abcdef");
	if (*format == 'p')
		ptr = ptr + ft_printn_base(va_arg(*holder, size_t), "0123456789abcdef");
	if (*format == 'c')
		ptr = ptr + ft_print_char(va_arg(*holder, int));
	if (*format == 's')
		ptr = ptr + ft_print_str(va_arg(*holder, char *));
	if (*format == '%')
		ptr = ptr + write(1, "%", 1);
	return (0);
}

int	ft_printf(char const *format, ...)
{	
	va_list	key_list;
	int		printptr;
	size_t	i;
	
	va_start(key_list, format);
	i = 0;
	printptr = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			printptr += keyholder(key_list, format[i + 1]);
			i++;
		}
		else
		{
			printptr += strings(format[i]);
			i++;
		}
	}
	va_end(key_list);
	return (printptr);
}

int	main(void)
{
	char	*str;
	
	str = "hola";

	ft_printf("El string es: %s\n", str);
	printf("El string es: %s\n", str);
	return (0);
}
