/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:37:35 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/08 16:15:58 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 124)
		right(game);
	else if (keycode == 126)
		up(game);
	else if (keycode == 123)
		left(game);
	else if (keycode == 125)
		down(game);
	else if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	right(t_game *game)
{
	if (game->map[game->pcoord->i][game->pcoord->j + 1] != '1')
	{
		game->player = mlx_xpm_file_to_image(game->mlx, "./image/zombie.xpm",
				&game->width, &game->height);
		game->mouves++;
		if (game->map[game->pcoord->i][game->pcoord->j + 1] == 'C')
		{
			game->collect--;
			game->map[game->pcoord->i][game->pcoord->j + 1] = '0';
			ft_wall(game);
		}
		finish(game, game->pcoord->i, game->pcoord->j + 1);
		game->map[game->pcoord->i][game->pcoord->j + 1] = 'P';
		if(game->pcoord->i == game->ecoord->i && game->pcoord->j == game->ecoord->j)
		{
			mlx_put_image_to_window(game->mlx, game-> mlx_win,
					game->background, game->pcoord->j * 50, game->pcoord->i * 50);
			game->map[game->pcoord->i][game->pcoord->j] = 'E';
		}
		else
			game->map[game->pcoord->i][game->pcoord->j] = '0';
		ft_wall(game);
		ft_putnbr_fd(game->mouves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	up(t_game *game)
{
	if (game->map[game->pcoord->i - 1][game->pcoord->j] != '1')
	{	
		game->mouves++;
		if (game->map[game->pcoord->i - 1][game->pcoord->j] == 'C')
		{
			game->collect--;
			game->map[game->pcoord->i - 1][game->pcoord->j] = '0';
			ft_wall(game);
		}
		finish(game, game->pcoord->i - 1, game->pcoord->j);
		game->map[game->pcoord->i - 1][game->pcoord->j] = 'P';
		if(game->pcoord->i == game->ecoord->i && game->pcoord->j == game->ecoord->j)
		{
			mlx_put_image_to_window(game->mlx, game-> mlx_win,
					game->background, game->pcoord->j * 50, game->pcoord->i * 50);
			game->map[game->pcoord->i][game->pcoord->j] = 'E';
		}
		else
			game->map[game->pcoord->i][game->pcoord->j] = '0';
		ft_wall(game);
		ft_putnbr_fd(game->mouves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	left(t_game *game)
{
	if (game->map[game->pcoord->i][game->pcoord->j - 1] != '1')
	{
		game->mouves++;
		game->player = mlx_xpm_file_to_image(game->mlx, "./image/zombiere.xpm",
				&game->width, &game->height);
		if (game->map[game->pcoord->i][game->pcoord->j - 1] == 'C')
		{
			game->collect--;
			game->map[game->pcoord->i][game->pcoord->j - 1] = '0';
			ft_wall(game);
		}
		finish(game, game->pcoord->i, game->pcoord->j - 1);
		game->map[game->pcoord->i][game->pcoord->j - 1] = 'P';
		if(game->pcoord->i == game->ecoord->i && game->pcoord->j == game->ecoord->j)
		{
			mlx_put_image_to_window(game->mlx, game-> mlx_win,
					game->background, game->pcoord->j * 50, game->pcoord->i * 50);
			game->map[game->pcoord->i][game->pcoord->j] = 'E';
		}
		else
			game->map[game->pcoord->i][game->pcoord->j] = '0';
		ft_wall(game);
		ft_putnbr_fd(game->mouves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	down(t_game *game)
{
	if (game->map[game->pcoord->i + 1][game->pcoord->j] != '1')
	{
		game->mouves++;
		if (game->map[game->pcoord->i + 1][game->pcoord->j] == 'C')
		{
			game->collect--;
			game->map[game->pcoord->i + 1][game->pcoord->j] = '0';
			ft_wall(game);
		}
		finish(game, game->pcoord->i + 1, game->pcoord->j);
		game->map[game->pcoord->i + 1][game->pcoord->j] = 'P';
		if(game->pcoord->i == game->ecoord->i && game->pcoord->j == game->ecoord->j)
		{
			mlx_put_image_to_window(game->mlx, game-> mlx_win,
					game->background, game->pcoord->j * 50, game->pcoord->i * 50);
			game->map[game->pcoord->i][game->pcoord->j] = 'E';
		}
		else
			game->map[game->pcoord->i][game->pcoord->j] = '0';
		ft_wall(game);
		ft_putnbr_fd(game->mouves, 1);
		ft_putchar_fd('\n', 1);
	}
}
