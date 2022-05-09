/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:37:27 by ghuertas          #+#    #+#             */
/*   Updated: 2022/04/22 02:01:41 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
size_t	ft_print_char(int c);
size_t	ft_print_nbr(int n);
size_t	ft_putnbr_base(int n, char *base);
size_t	ft_print_str(char *s);
size_t	ft_strlenv2(const char *s);

#endif
