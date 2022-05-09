/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:32:14 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/09 23:52:12 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	keyholder(const char **format, char key)
{
	if ((*format)[0] == '%' && (*format[1]) == key)
		return (++*format, 1);
	return (0);
}

static	int	numbers(char **format, va_list arg_list, size_t *i)
{
	int	output;

	output = 0;
	if (keyholder(format, 'd'))
		output = ft_print_nbr(va_arg(arg_list, int));
	else if (keyholder(format, 'i'))
		output = ft_print_nbr(va_arg(arg_list, int));
	else if (keyholder(format, 'u'))
		output = ft_print_nbr(va_arg(arg_list, unsigned int));
	else if (keyholder(format, 'x') || keyholder(format, 'X'))
		output = ft_printnbr_base(va_arg(arg_list, unsigned int));
	else if (keyholder(format, 'p'))
		output = write(1, "0x", 2) + ft_printnbr_base(va_arg(arg_list, size_t));
	return (*i += output);
}

static size_t	strings(char *s)
{
	if (!s)
		return (ft_print_str("(null)"), 6);
	ft_print_str(s);
	return (ft_strlenv2(s));
}

int	ft_printf(char const *__format, ...)
{	
	va_list	arg_list;
	size_t	i;
	char	*format;

	format = (char *)__format;
	va_start(arg_list, __format);
	i = 0;
	while (format && *format)
	{	
		if (keyholder(&format, 'c') && ++i)
			ft_print_char(va_arg(arg_list, int));
		else if (keyholder(&format, 's'))
			i += ft_print_str(va_arg(arg_list, char *));
		else if (numbers(&format, arg_list, &i))
			;
		else if (keyholder(&format, '%') && ++i)
			write(1, "%", 1);
		else
			ft_print_char(*format);
		ft_print_char(++i);
			format++;
	}
	return (va_end(arg_list), i);
}
/*int	main(void)
{
	char *s;

	ft_printf("%s", 23242424);
	return (0);
}
*/