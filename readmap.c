/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:56:21 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/12 23:46:28 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	numberline(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	readfile(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		print(2,"Error\nfile is empty Or does not exist\n");
		exit(EXIT_FAILURE);
	}
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

char	**readmap(char *path)
{
	int		i;
	int		fd;
	int		linefile;
	char	**lines;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print(2,"Error\nNo such File or Directory\n");
		exit(EXIT_FAILURE);
	}
	linefile = readfile(fd);
	lines = malloc(sizeof(char *) * (linefile + 1));
	if (!lines)
		return (NULL);
	close(fd);
	fd = open(path, O_RDONLY);
	while (i < linefile)
	{
		lines[i] = get_next_line(fd);
		i++;
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}
