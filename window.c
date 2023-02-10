/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:12:46 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/10 17:12:15 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_window(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx, game->len * 50, game->line * 50, "so_long");
	if (!game->mlx_win)
		return (0);
	game->player = mlx_xpm_file_to_image(game->mlx, "./image/zombie.xpm",
			&game->width, &game->height);
	if (!game->player)
	{
		destroy(game);
		print(2, "Error\n image error\n");
		exit(EXIT_FAILURE);
	}
	ft_images(game);
	return (1);
}

void	ft_images(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
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
			j++;
		}
		i++;
	}
}
