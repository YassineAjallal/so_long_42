/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:12:46 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/12 17:07:29 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_window(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx, game->len * 50,
			game->line * 50, "so_long");
	if (!game->mlx_win)
		return (0);
	ft_images(game);
	return (1);
}

void	ft_put_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->wall, j * 50, i * 50);
	else if (game->map[i][j] == 'P')
	{
		game->pcoord->j = j;
		game->pcoord->i = i;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, j * 50, i * 50);
	}
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->coin, j * 50, i * 50);
	else if (game->map[i][j] == 'E')
	{
		game->ecoord->i = i;
		game->ecoord->j = j;
		mlx_put_image_to_window(game->mlx, game-> mlx_win,
			game->door, game->ecoord->j * 50, game->ecoord->i * 50);
	}
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game-> mlx_win,
			game->background, j * 50, i * 50);
}

void	ft_images(t_game *game)
{
	int	i;
	int	j;
	int	img;

	destroy(game);
	img = fill_images(game);
	if (!img)
	{
		print(2, "Error\nimage error\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			ft_put_image(game, i, j);
			j++;
		}
		i++;
	}
}
