/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:12:46 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/06 15:49:02 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_window(t_game *game)
{
	int line;
	int len;

	line = numberline(game->map);
	len = ft_strlennl(game->map[0]);
	game->mlx_win = mlx_new_window(game->mlx, len * 50, line * 50, "so_long");
	game->player = mlx_xpm_file_to_image(game->mlx, "./image/zombie.xpm", &game->img_width, &game->img_height);
	ft_wall(game);
}

void ft_wall(t_game *game)
{
	int 	i;
	int 	j;
	
	i = 0;
	game->wall = mlx_xpm_file_to_image(game->mlx, "./image/walls.xpm", &game->img_width, &game->img_height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "./image/food.xpm", &game->img_width, &game->img_height);
	game->door = mlx_xpm_file_to_image(game->mlx, "./image/door.xpm", &game->img_width, &game->img_height);
	game->background = mlx_xpm_file_to_image(game->mlx, "./image/background.xpm", &game->img_width, &game->img_height);
	while (game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, j * 50, i * 50);
			else if (game->map[i][j] == 'P')
			{
				game->pcoord->j = j;
				game->pcoord->i = i;
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, j * 50, i * 50);
			}
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->coin, j * 50, i * 50);
			else if (game->map[i][j] == 'E' && game->collect == 0)
				mlx_put_image_to_window(game->mlx,game-> mlx_win, game->door, j * 50, i * 50);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx,game-> mlx_win, game->background, j * 50, i * 50);
			j++;
		}
		i++;
	}
}