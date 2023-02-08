/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:57:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/08 17:16:29 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

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
	game->pcoord = malloc(sizeof(t_coord));
	game->ecoord = malloc(sizeof(t_coord));
	if (!game || !game->pcoord || !game->ecoord)
		return (0);
	game->map = readmap(av[1]);
	game->line = numberline(game->map);
	game->len = ft_strlennl(game->map[0]);
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
	else if (game->line * 50 > SCREEN_HEIGHT || game->len * 50 > SCREEN_WIDTH)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("map is to long\n", 2);
		ft_free2d(game->map);
		exit(EXIT_FAILURE);
	}
	ft_free2d(game->map);
	game->pcoord->i = 0;
	game->pcoord->j = 0;
	game->mouves = 0;
	game->map = readmap(av[1]);
	game->mlx = mlx_init();
	ft_window(game);
	mlx_hook(game->mlx_win, 2, 0, &key_hook, game);
	mlx_loop(game->mlx);
}
