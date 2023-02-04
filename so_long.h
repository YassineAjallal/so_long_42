/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:24:46 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/04 14:22:26 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"

int	ft_checkex(char *file);

int numberline(char **map);
char **readmap(char *path);

void ft_checkpath(char **map);
int ft_search(char **map);
int isequal(char *line);
int ft_strlennl(char *str);
#endif