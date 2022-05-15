/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:32:14 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/15 15:48:09 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	keyholder(va_list holder, char format)
{
	int		ptr;

	ptr = 0;
	if (format == 'd' || format == 'i')
		ptr += ft_printn_base(va_arg(holder, int), "0123456789");
	if (format == 'u')
		ptr += ft_printnu_base(va_arg(holder, unsigned int), "0123456789");
	if (format == 'X')
		ptr += ft_printn_base(va_arg(holder, int), "0123456789ABCDEF");
	if (format == 'x')
		ptr += ft_printn_base(va_arg(holder, unsigned), "0123456789abcdef");
	if (format == 'p')
		ptr += ft_print_str("0x")
			+ ft_printn_base(va_arg(holder, size_t), "0123456789abcdef");
	if (format == 'c')
		ptr += ft_print_char(va_arg(holder, int));
	if (format == 's')
		ptr += ft_print_str(va_arg(holder, char *));
	if (format == '%')
		ptr += write(1, "%", 1);
	return (ptr);
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
			printptr += ft_print_char(format[i]);
		i++;
	}
	va_end(key_list);
	return (printptr);
}
/*
int	main(void)
{
	char			*str;
	int				n;
	char			c;
	unsigned int	un;

	str = "Marvin is a cat";
	n = 43;
	c = '0';
	un = 234;
	ft_printf("El string es: %s\n", str);
	printf("El string es: %s\n", str);
	ft_printf("El string es: %s\n", str);
	printf("El string es: %s\n", str);
	ft_printf("El numero es: %d\n", n);
	printf("El numero es: %d\n", n);
	ft_printf("El char es: %c\n", c);
	printf("El char es: %c\n", c);
	ft_printf("El n con i es: %i\n", n);
	printf("El n con i es: %i\n", n);
	ft_printf("El n con u es: %u\n", n);
	printf("El n con u es: %u\n", n);
	ft_printf("El n con X es: %X\n", n);
	printf("El n con X es: %X\n", n);
	ft_printf("El n con x es: %x\n", n);
	printf("El n con x es: %x\n", n);
	ft_printf("Recibiendo: %%\n");
	printf("Recibiendo: %%\n");
	ft_printf("Recibiendo void*: %p\n", str);
	printf("Recibiendo void*: %p\n", str);
	return (0);
}
*/