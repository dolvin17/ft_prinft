/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:42:00 by ghuertas          #+#    #+#             */
/*   Updated: 2022/04/21 08:45:25 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlenv2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}