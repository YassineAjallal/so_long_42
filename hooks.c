/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:37:35 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/06 12:37:48 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 124)
	{
		game->player = mlx_xpm_file_to_image(game->mlx, "./image/zombie.xpm", &game->img_width, &game->img_height);
		right(game);
	}
	else if (keycode == 126)
		up(game);
	else if (keycode == 123)
	{
		game->player = mlx_xpm_file_to_image(game->mlx, "./image/zombiere.xpm", &game->img_width, &game->img_height);
		left(game);
	}
	else if (keycode == 125)
		down(game);
	else if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void right(t_game *game)
{
	if(game->map[game->posy][game->posx + 1] != '1')
	{	
		if (game->map[game->posy][game->posx + 1] == 'C')
		{
			game->collect--;
			game->map[game->posy][game->posx + 1] = '0';
			ft_wall(game);
		}
		if (game->map[game->posy][game->posx + 1] == 'E')
		{
			mlx_destroy_window(game->mlx, game->mlx_win);
			write(1, "you finish\n", 11);
			exit(EXIT_SUCCESS);
		}
		game->map[game->posy][game->posx + 1] = 'P';
		game->map[game->posy][game->posx] = '0';
		ft_wall(game);
	}
}
void up(t_game *game)
{
	if(game->map[game->posy - 1][game->posx] != '1')
	{	
		if (game->map[game->posy - 1][game->posx] == 'C')
		{
			game->collect--;
			game->map[game->posy - 1][game->posx] = '0';
			ft_wall(game);
		}
		if (game->map[game->posy - 1][game->posx] == 'E')
		{
			mlx_destroy_window(game->mlx, game->mlx_win);
			write(1, "you finish\n", 11);
			exit(EXIT_SUCCESS);
		}
		game->map[game->posy - 1][game->posx] = 'P';
		game->map[game->posy][game->posx] = '0';
		ft_wall(game);
	}
}
void left (t_game *game)
{
	if(game->map[game->posy][game->posx - 1] != '1')
	{	
		if (game->map[game->posy][game->posx - 1] == 'C')
		{
			game->collect--;
			game->map[game->posy][game->posx - 1] = '0';
			ft_wall(game);
		}
		if (game->map[game->posy][game->posx - 1] == 'E')
		{
			mlx_destroy_window(game->mlx, game->mlx_win);
			write(1, "you finish\n", 11);
			exit(EXIT_SUCCESS);
		}
		game->map[game->posy][game->posx - 1] = 'P';
		game->map[game->posy][game->posx] = '0';
		ft_wall(game);
	}
}
void down(t_game *game)
{
	if(game->map[game->posy + 1][game->posx] != '1')
	{	
		if (game->map[game->posy + 1][game->posx] == 'C')
		{
			game->collect--;
			game->map[game->posy + 1][game->posx] = '0';
			ft_wall(game);
		}
		if (game->map[game->posy + 1][game->posx] == 'E')
		{
			mlx_destroy_window(game->mlx, game->mlx_win);
			write(1, "you finish\n", 11);
			exit(EXIT_SUCCESS);
		}
		game->map[game->posy + 1][game->posx] = 'P';
		game->map[game->posy][game->posx] = '0';
		ft_wall(game);
	}
}