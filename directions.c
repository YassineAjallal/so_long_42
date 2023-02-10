/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:54:48 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/10 17:00:11 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_game *game)
{
	if (game->map[game->pcoord->i][game->pcoord->j + 1] != '1')
	{
		game->mouves++;
		ft_player(game, "./image/zombie.xpm");
		if (game->map[game->pcoord->i][game->pcoord->j + 1] == 'C')
		{
			game->collect--;
			game->map[game->pcoord->i][game->pcoord->j + 1] = '0';
			ft_images(game);
		}
		finish(game, game->pcoord->i, game->pcoord->j + 1);
		game->map[game->pcoord->i][game->pcoord->j + 1] = 'P';
		if (game->pcoord->i == game->ecoord->i
			&& game->pcoord->j == game->ecoord->j)
		{
			mlx_put_image_to_window(game->mlx, game-> mlx_win,
				game->background, game->pcoord->j * 50, game->pcoord->i * 50);
			game->map[game->pcoord->i][game->pcoord->j] = 'E';
		}
		else
			game->map[game->pcoord->i][game->pcoord->j] = '0';
		ft_images(game);
		print(1, "mouves -----> %d\n", game->mouves);
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
			ft_images(game);
		}
		finish(game, game->pcoord->i - 1, game->pcoord->j);
		game->map[game->pcoord->i - 1][game->pcoord->j] = 'P';
		if (game->pcoord->i == game->ecoord->i
			&& game->pcoord->j == game->ecoord->j)
		{
			mlx_put_image_to_window(game->mlx, game-> mlx_win,
				game->background, game->pcoord->j * 50, game->pcoord->i * 50);
			game->map[game->pcoord->i][game->pcoord->j] = 'E';
		}
		else
			game->map[game->pcoord->i][game->pcoord->j] = '0';
		ft_images(game);
		print(1, "mouves -----> %d\n", game->mouves);
	}
}

void	left(t_game *game)
{
	if (game->map[game->pcoord->i][game->pcoord->j - 1] != '1')
	{
		game->mouves++;
		ft_player(game, "./image/zombiere.xpm");
		if (game->map[game->pcoord->i][game->pcoord->j - 1] == 'C')
		{
			game->collect--;
			game->map[game->pcoord->i][game->pcoord->j - 1] = '0';
			ft_images(game);
		}
		finish(game, game->pcoord->i, game->pcoord->j - 1);
		game->map[game->pcoord->i][game->pcoord->j - 1] = 'P';
		if (game->pcoord->i == game->ecoord->i
			&& game->pcoord->j == game->ecoord->j)
		{
			mlx_put_image_to_window(game->mlx, game-> mlx_win,
				game->background, game->pcoord->j * 50, game->pcoord->i * 50);
			game->map[game->pcoord->i][game->pcoord->j] = 'E';
		}
		else
			game->map[game->pcoord->i][game->pcoord->j] = '0';
		ft_images(game);
		print(1, "mouves -----> %d\n", game->mouves);
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
			ft_images(game);
		}
		finish(game, game->pcoord->i + 1, game->pcoord->j);
		game->map[game->pcoord->i + 1][game->pcoord->j] = 'P';
		if (game->pcoord->i == game->ecoord->i
			&& game->pcoord->j == game->ecoord->j)
		{
			mlx_put_image_to_window(game->mlx, game-> mlx_win,
				game->background, game->pcoord->j * 50, game->pcoord->i * 50);
			game->map[game->pcoord->i][game->pcoord->j] = 'E';
		}
		else
			game->map[game->pcoord->i][game->pcoord->j] = '0';
		ft_images(game);
		print(1, "mouves -----> %d\n", game->mouves);
	}
}
