/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:32:14 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/13 20:27:44 by ghuertas         ###   ########.fr       */
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
		ptr = ptr + ft_printnu_base(va_arg(holder, unsigned int), "0123456789");
	if (format == 'X')
		ptr = ptr + ft_printn_base(va_arg(holder, int), "0123456789ABCDEF");
	if (format == 'x')
		ptr = ptr + write(1, "0x", 2)
			+ ft_printn_base(va_arg(holder, unsigned), "0123456789abcdef");
	if (format == 'p')
		ptr = ptr + write(1, "0x10", 4)
			+ ft_printn_base(va_arg(holder, size_t), "0123456789abcdef");
	if (format == 'c')
		ptr = ptr + ft_print_char(va_arg(holder, int));
	if (format == 's')
		ptr = ptr + ft_print_str(va_arg(holder, char *));
	if (format == '%')
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
			i++;
			printptr += keyholder(key_list, format[i]);
		}
		else
			printptr += ft_print_char(format[i]);
		i++;
	}
	va_end(key_list);
	return (printptr);
}

int	main(void)
{
	char			*str;
	int				n;
	char			c;
	unsigned int	un;

	str = "Marvin is a cat";
	n = -12;
	c = '0';
	un = 234;
	ft_printf("El string es: %s\n", NULL);
	printf("El string es: %s\n", NULL);
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
