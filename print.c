/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmouve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:28:37 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/10 16:40:08 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print(int fd, char *s, ...)
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
				ft_putnbr_fd(va_arg(par, int), fd);
		}
		else
			ft_putchar_fd(s[i], fd);
		if (s[i])
			i++;
	}
}