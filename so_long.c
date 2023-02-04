/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:57:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/04 14:49:06 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	char **map;
	
	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Bad Usage\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_checkex(av[1]))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Extension Not Valid\n", 2);
		exit(EXIT_FAILURE);
	}
	map = readmap(av[1]);
	if (!checkwall(map) || !checkchar(map))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid Map\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (!ft_checkvalid(map))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid PATH in map\n", 2);
		exit(EXIT_FAILURE);
	}
}
