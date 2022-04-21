/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:32:14 by ghuertas          #+#    #+#             */
/*   Updated: 2022/04/21 09:15:09 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"
// cspdiuxX %
static int	keyholder(const char **format, char key)
{
	if ((*format)[0] == '%' && (*format[1]) == key)
		return (1);
	return (0);
}

static	int	numbers(char **format, va_list arg)
{
	size_t	output;

	output = 0;
	if (keyholder(format, 'd') || (format 'i'))
		output = ft_print_nbr(va_arg(arg, int));
	else if (keyholder(format, 'u'))
		output = ft_print_nbr(va_arg(arg, unsigned int));
	else if (keyholder(format, 'x' || (format 'X'))
		output = ft_printnbr_base(va_arg(arg, unsigned int));
	else if (keyholder(format, 'p'))
		output = ft_print_str("0x") + ft_printnbr_base(va_arg(arg, size_t)));
	return(output);

}

static size_t	strings(char *s)
{
	if (!s)
		return (ft_print_str("(NULL"));
	ft_print_str(s);
	return (ft_strlenv2(str));
}

int	ft_printf(char const *format, ...)
{	
	va_list	arg;
	size_t	i;

	va_start(arg, format);
	i = 0;
	while (format && *format)
	{	
		if (*format == '%' && format[1] == 'c')
		{		
			ft_print_char(va_arg(arg, int));
		}
		else if (*format == '%' && format[1] == 's')
		{		
			ft_print_str(va_arg(arg, char *));
		}
		if (*format == '%' && format[1] == 'p')
		{
			ft_printnbr_base(va_arg(arg, unsigned int));
		}
		else if (*format == '%' && format[1] == 'd')
		{
			ft_print_nbr(va_arg(arg, unsigned int));
		}
		else if (*format == '%' && format[1] == 'i')
		{
			ft_print_nbr(va_arg(arg, unsigned int));
		}
		else if (*format == '%' && format[1] == 'u')
		{
			ft_print_nbr(va_arg(arg, unsigned int));
		}
		else if (*format == '%' && format[1] == 'x')
		{
			ft_printnbr_base(va_arg(arg, unsigned int));
		}
		else if (*format == '%' && format[1] == 'X')
		{
			ft_printnbr_base(va_arg(arg, unsigned int));
		}
		else
			*format == '%' && format[1] == '%';
			{
			ft_print_char(va_arg(arg, int));
			}
			++format;
}
	i = va_arg(arg, size_t);

	return (va_end(arg), i);
int	main(void)
{
	char *s;

	ft_printf("%p", 23242424);
	return (0);
}