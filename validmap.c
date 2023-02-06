/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:30:06 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/06 12:28:05 by yajallal         ###   ########.fr       */
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

int checkchar(t_game *game)
{
	int i;
	int j;

	i = 0;
	game->player = 0;
	game->exit = 0;
	game->collect = 0;
	while(game->map[i])
	{
		j = 0;
		while (j < ft_strlennl(game->map[i]))
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != 'P' && game->map[i][j] != 'E' && game->map[i][j] != '1' 
				&& game->map[i][j] != '0')
			{
				return (0);
			}
			if (game->map[i][j] == 'C')
				game->collect++;
			else if (game->map[i][j] == 'P')
				game->positions++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
	if (game->collect < 1 || game->positions != 1 || game->exit != 1)
		return (0);
	return (1);
}