/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:23:23 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/07 17:51:08 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_replace(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{	
			if (map[i][j] == 'P')
			{
				if (map[i - 1][j] != '1' && map[i - 1][j] != 'P')
					map[i - 1][j] = 'P';
				if (map[i + 1][j] != '1' && map[i + 1][j] != 'P')
					map[i + 1][j] = 'P';
				if (map[i][j + 1] != '1' && map[i][j + 1] != 'P')
					map[i][j + 1] = 'P';
				if (map[i][j - 1] != '1' && map[i][j - 1] != 'P')
					map[i][j - 1] = 'P';
			}
			j++;
		}
		i++;
	}
}

void	ft_fill(char **map)
{
	int	i;

	i = 0;
	while (i < numberline(map) * ft_strlen(map[0]))
	{
		ft_replace(map);
		i++;
	}
}

int	ft_checkvalid(char **map)
{
	int	i;
	int	j;

	ft_fill(map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][i] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
