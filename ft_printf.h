/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:37:27 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/13 20:19:02 by ghuertas         ###   ########.fr       */
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
