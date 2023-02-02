/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:56:21 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/02 15:04:20 by yajallal         ###   ########.fr       */
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
	if (!lines)
		return (NULL);
	fd = open(path, O_RDONLY);
	while (j < i)
	{
		lines[j] = get_next_line(fd);
		j++;
	}
	lines[j] = NULL;
	return (lines);
}