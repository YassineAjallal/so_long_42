/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:22:14 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/12 23:20:50 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkex(char *file)
{
	char	*tmp;

	tmp = file + (ft_strlen(file) - 4);
	if (ft_strnstr(tmp, ".ber", 4))
		return (1);
	return (0);
}
