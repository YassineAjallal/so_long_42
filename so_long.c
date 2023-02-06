/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:57:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/06 12:26:38 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int ac, char **av)
{
	t_game *game;
	
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

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->map = readmap(av[1]);
	if (!checkwall(game->map) || !checkchar(game))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid Map\n", 2);
		ft_free2d(game->map);
		exit(EXIT_FAILURE);
	}
	else if (!ft_checkvalid(game->map))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid PATH in map\n", 2);
		ft_free2d(game->map);
		exit(EXIT_FAILURE);
	}
	ft_free2d(game->map);

 	/*--------------------------*/
	game->posx = 0;
	game->posy = 0;
	game->map = readmap(av[1]);
	game->mlx = mlx_init();
	ft_window(game);
	mlx_hook(game->mlx_win, 2, 0, &key_hook, game);
	mlx_loop(game->mlx);
}
