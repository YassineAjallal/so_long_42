/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:37:35 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/10 16:41:18 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	directions(int keycode, t_game *game)
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
		destroy(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void ft_player(t_game *game, char *img)
{
		game->player = mlx_xpm_file_to_image(game->mlx, img,
				&game->width, &game->height);
		if (!game->player)
			destroy(game);
}
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
		if(game->pcoord->i == game->ecoord->i && game->pcoord->j == game->ecoord->j)
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
		if(game->pcoord->i == game->ecoord->i && game->pcoord->j == game->ecoord->j)
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
		if(game->pcoord->i == game->ecoord->i && game->pcoord->j == game->ecoord->j)
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
		if(game->pcoord->i == game->ecoord->i && game->pcoord->j == game->ecoord->j)
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
