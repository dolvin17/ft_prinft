/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:37:27 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/14 22:53:39 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(char const *format, ...);
int	ft_print_char(int c);
int	ft_printn_base(int n, char *base);
int	ft_printnu_base(unsigned int n, char *base);
int	ft_print_str(char *s);
size_t	ft_strlenv2(const char *s);

#endif
