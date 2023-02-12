/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:22:22 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/12 13:24:10 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

void free_game(t_game *game)
{
	ft_free2d(game->map);
	// free(game->background);
	// free(game->player);
	// free(game->door);
	// free(game->coin);
	// free(game->wall);
	free(game->pcoord);
	free(game->ecoord);
	free(game);
}
