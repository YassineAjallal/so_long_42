/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:12:46 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/05 00:55:52 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_window(char **map, void *mlx)
{
	int line;
	void	*mlx_win;
	int len;

	line = numberline(map);
	len = ft_strlennl(map[0]);
	mlx_win = mlx_new_window(mlx, len * 50, line * 50, "so_long");
	ft_wall(map, mlx, mlx_win);
}

void ft_wall(char **map, void *mlx, void *mlx_win)
{
	void *wall;
	void *pacman;
	int		img_width;
	int		img_height;
	int 	i;
	int 	j;
	
	i = 0;
	wall = mlx_xpm_file_to_image(mlx, "./image/wall.xpm", &img_width, &img_height);
	pacman = mlx_xpm_file_to_image(mlx, "./image/Pacman.xpm", &img_width, &img_height);
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, wall, j * 50, i * 50);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, pacman, j * 50, i * 50);
			j++;
		}
		i++;
	}
}