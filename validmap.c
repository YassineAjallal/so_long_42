/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:30:06 by yajallal          #+#    #+#             */
/*   Updated: 2023/01/30 20:25:29 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int numberline(char **map)
{
	int i;

	i = 0;
	while(map[i])
		i++;
	return (i);
}

char **readmap(char *path)
{
	int i;
	int fd;
	int j;
	char **lines;

	i = 0;
	j = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	lines = malloc(sizeof(char *) * (i + 1));
	fd = open(path, O_RDONLY);
	while (j < i)
	{
		lines[j] = get_next_line(fd);
		j++;
	}
	lines[j] = NULL;
	return (lines);
}

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
		if (line[i] != line[0])
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
	i = 0;
	
	if (!isequal(map[0]) || !isequal(map[len - 1]) || !checklen(map))
		return (0);
	while (i < len)
	{
		linelen = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][linelen - 2] != '1')
			return (0);
		i++;
	}
	return (1);
	
}

int main()
{
	int i;
	char **map;

	map = readmap("./map_files/invalid.ber");
	printf("%d\n", checkwall(map));
}