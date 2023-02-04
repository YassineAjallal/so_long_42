/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:56:21 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/04 20:14:24 by yajallal         ###   ########.fr       */
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
	char *line;

	i = 0;
	j = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	lines = malloc(sizeof(char *) * (i + 1));
	if (!lines)
		return (NULL);
	fd = open(path, O_RDONLY);
	while (j < i)
	{
		lines[j] = get_next_line(fd);
		j++;
	}
	lines[j] = NULL;
	close(fd);
	return (lines);
}