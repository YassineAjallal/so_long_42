/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:22:22 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/12 17:06:14 by yajallal         ###   ########.fr       */
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

void	free_game(t_game *game)
{
	ft_free2d(game->map);
	free(game->pcoord);
	free(game->ecoord);
	game->pcoord = NULL;
	game->ecoord = NULL;
	free(game);
	game = NULL;
}
