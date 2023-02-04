/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:30:06 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/04 20:12:12 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlennl(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] != '\n')
			i++;
	return (i);
}

int checklen(char **map)
{
	int i;
	int len;
	
	i = 1;
	len = ft_strlennl(map[0]);
	while (map[i])
	{
		
		if (len != ft_strlennl(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int isequal(char *line)
{
	int i;

	i = 1;
	
	while(i < ft_strlen(line) - 1)
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
int checkwall(char **map)
{
	int i;
	int len;
	int linelen;
	
	len = numberline(map);
	i = 1;
	
	if (!isequal(map[0]) || !isequal(map[len - 1]) || !checklen(map))
		return (0);
	while (i < len - 1)
	{
		linelen = ft_strlennl(map[i]);
		if (map[i][0] != '1' || map[i][linelen - 1] != '1')
			return (0);	
		i++;
	}
	return (1);
}

int checkchar(char **map)
{
	int i;
	int j;
	int player;
	int exit;
	int collect;

	i = 0;
	player = 0;
	exit = 0;
	collect = 0;
	while(map[i])
	{
		j = 0;
		while (j < ft_strlennl(map[i]))
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '1' 
				&& map[i][j] != '0')
			{
				return (0);
			}
			if (map[i][j] == 'C')
				collect++;
			else if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (collect < 1 || player != 1 || exit != 1)
		return (0);
	return (1);
}