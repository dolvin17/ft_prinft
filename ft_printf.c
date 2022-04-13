/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:32:14 by ghuertas          #+#    #+#             */
/*   Updated: 2022/04/13 06:11:08 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_printf(char const *, ...)

{	
	int	i;
	//step 1 -> inicializar argumentos
	va_list	arg; //declara una variable, arg, que usamos para manipular la lista de argumentos.

	va_start(arg, format); // inicializo arg con el ultimo argumento fijo de la funcion. En otras palabras, format. 
	//va_start() usa esto para averiguar donde empiezan los argumentos de la variable.
	i = 0;
	while (format)
		{
			



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
int	main(void)
{

}