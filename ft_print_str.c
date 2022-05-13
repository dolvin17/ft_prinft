/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 04:49:13 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/13 20:17:39 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	if (!s)
		return (ft_print_str("(null)"), 6);
	write(1, &s[0], ft_strlenv2(s));
	return (ft_strlenv2(s));
}
