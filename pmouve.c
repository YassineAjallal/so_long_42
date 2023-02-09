/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmouve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:28:37 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/09 13:05:46 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pmouve(char *s, ...)
{
	va_list	par;
	int		i;

	va_start(par, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'd')
				ft_putnbr_fd(va_arg(par, int), 1);
		}
		else
			ft_putchar_fd(s[i], 1);
		if (s[i])
			i++;
	}
}