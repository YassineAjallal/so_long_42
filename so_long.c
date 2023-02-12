/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:57:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/12 17:05:32 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_error(int ac, char **av)
{
	if (ac != 2)
	{
		print(2, "Error\nBad Usage\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_checkex(av[1]))
	{
		print(2, "Error\nInvalid File\n");
		exit(EXIT_FAILURE);
	}
}

void	map_check(t_game *game, char **av)
{
	game->map = readmap(av[1]);
	game->line = numberline(game->map);
	game->len = ft_strlennl(game->map[0]);
	if (!checkwall(game->map) || !checkchar(game))
	{
		print(2, "Error\n Invalid map\n");
		ft_free2d(game->map);
		exit(EXIT_FAILURE);
	}
	else if (!ft_checkvalid(game->map))
	{
		print(2, "Error\nInvalid PATH\n");
		ft_free2d(game->map);
		exit(EXIT_FAILURE);
	}
	else if (game->line * 50 > SCREEN_HEIGHT || game->len * 50 > SCREEN_WIDTH)
	{
		print(2, "Error\nmap to long\n");
		ft_free2d(game->map);
		exit(EXIT_FAILURE);
	}
	ft_free2d(game->map);
}

void	init(t_game *game, char **av)
{
	int	img;
	int	win;

	game->mouves = 0;
	game->pdir = 'n';
	game->map = readmap(av[1]);
	game->mlx = mlx_init();
	img = fill_images(game);
	if (!img)
	{
		print(2, "Error\nimage error\n");
		ft_free2d(game->map);
		exit(EXIT_FAILURE);
	}
	win = ft_window(game);
	if (!win)
	{
		print(2, "Error\nwindow error\n");
		ft_free2d(game->map);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	arg_error(ac, av);
	game = malloc(sizeof(t_game));
	game->pcoord = malloc(sizeof(t_coord));
	game->ecoord = malloc(sizeof(t_coord));
	if (!game)
		return (0);
	if (!game->pcoord || !game->ecoord)
	{
		free(game);	
		return (0);
	}
	map_check(game, av);
	init(game, av);
	mlx_hook(game->mlx_win, 17, 0, &ondestroy, game);
	mlx_hook(game->mlx_win, 2, 0, &directions, game);
	mlx_loop(game->mlx);
	exit(EXIT_SUCCESS);
}
