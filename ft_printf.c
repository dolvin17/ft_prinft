/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:32:14 by ghuertas          #+#    #+#             */
/*   Updated: 2022/04/15 03:09:03 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
// cspdiuxX %
int	ft_printf(char const *format, ...)

{	
	int	i;
	//step 1 -> inicializar argumentos
	va_list	arg; //declara una variable, arg, que usamos para manipular la lista de argumentos.

	va_start(arg, format); // inicializo arg con el ultimo argumento fijo de la funcion. En otras palabras, format. 
	//va_start() usa esto para averiguar donde empiezan los argumentos de la variable.
	i = 0;
	while (*format)
	{
		if (*format) // encuentro un specifier, %c
			
			// dado specifier = %c
			ft_putchar(va_arg(arg, int));
			else if (*format == '%' && format[1] =='s') //encuentro un specifier, %s
			// dado specifier = %s
			ft_putstr(va_arg(arg, char *));
			else if (*format == '%' && format[1] == 'p') //encuentro un specifier, %p
			// dado specifier = %p
			ft_putnbrbase(va_arg(arg, long int));
			else if (*format == '%' && format[1] == 'd') //encuentro un specifier, %d
			// dado specifier = %d
			ft_putnbr(va_arg(arg, int));
			else if (*format == '%' && format[1] == 'i') //encuentro un specifier, %i
			// dado specifier = %i
			ft_putnbr(va_arg(arg, int));
			else if (*format == '%' && format[1] == 'u') //encuentro un specifier, %u
			// dado specifier = %u
			ft_putnbr(va_arg(arg, unsigned long));
			else if (*format == '%' && format[1] == 'x') //encuentro un specifier, %x
			// dado specifier = %x
			ft_putnbrbase(va_arg(arg, long int));
			else if *format == '%' && format[1] == 'X') //encuentro un specifier, %X
			// dado specifier = %X
			ft_putnbrbase(va_arg(arg, long int));
			else *format == '%' && format[1] == '%') //encuentro un specifier, %%
			//dado specifier =%%
		++format;
	}
}
	//step 2 -> obtener y ejecutar argumentos.
	i = va_arg(arg, int) //obtiene el siguiente argumento de la lista de arguentos. El 2nd parametro para va_arg()
	//es el tipo de dato del argumento que esperamos. 
	
	//NOTA: va_arg() nunca recibirá argumentos de tipo char, short int, or float. va_arg() solo acepta argumentos
	//de tipo char *, unsigned int, int o double. 

	//step 3 -> cerramos la lista de argumentos. 
	va_end(arg); //finalmente cuando terminamos de procesar todos los argumentos, llamamos a va_end(), que 
	//realiza cualquier limpieza necesaria.
}
static void ft_putstr(char *s)
{
	int i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
}
static void ft_putchar(int c)
{
	write (1, &c, 1);
}
static void	ft_putnbr_base(int n)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_base(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(n * -1);
	}
	else if (n < 16)
		ft_putchar((char)(n + '0'));
	else
	{
		ft_putnbr_base(n / 16);
		ft_putchar(n % 16 + '0');
	}
}
static void	ft_putnbr(int n)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n < 10)
		ft_putchar((char)(n + '0'));
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

int	main(void)
{

}


/**
tipo de dato (para obtener en el va_arg) para cada mask
string formato: "HOLA %c,%d,%s"







*/


printf("%c", 'c')