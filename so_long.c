/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:57:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/05 00:56:56 by yajallal         ###   ########.fr       */
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
		ft_free2d(map);
		exit(EXIT_FAILURE);
	}
	else if (!ft_checkvalid(map))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid PATH in map\n", 2);
		ft_free2d(map);
		exit(EXIT_FAILURE);
	}
	ft_free2d(map);
	map = readmap(av[1]);
	void	*mlx;
	// void	*mlx_win = NULL;
	// void	*img;
	// char	*relative_path = "./image/wall.xpm";
	// int		img_width;
	// int		img_height;
	// int 	i;
	// int 	j;
	mlx = mlx_init();
	// img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	// mlx_put_image_to_window(mlx, mlx_win, img, 50, 0);
	// mlx_put_image_to_window(mlx, mlx_win, img, 100, 0);
	ft_window(map, mlx);
	// i = 0;
	// while (map[i])
	// {
	// 	j = 0;
	// 	while(map[i][j] && map[i][j] != '\n')
	// 	{
	// 		if (map[i][j] == '1')
	// 			mlx_put_image_to_window(mlx, mlx_win, img, j * 50, i * 50);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// ft_wall(map, mlx, mlx_win);
	mlx_loop(mlx);
}
