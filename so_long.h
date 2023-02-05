/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:24:46 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/05 16:42:23 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>


typedef struct s_game 
{
	char **map;
	void *mlx;
	void *mlx_win;
	void *player;
	void *coin;
	void *wall;
	void *door;
	void *background;
	int img_width;
	int img_height;
	int posx;
	int posy;
} t_game;
// get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *save);
char	*ft_copy(char *save);
char	*ft_getnews(char *save);

// so_long.c

int	ft_checkex(char *file);

int numberline(char **map);
char **readmap(char *path);

void ft_replace(char **map);
void ft_fill(char **map);
int ft_checkvalid(char **map);

int checkwall(char **map);
int checkchar(char **map);
int checklen(char **map);
int isequal(char *line);
int ft_strlennl(char *str);

// arrays.c 
void	ft_free2d(char **str);

// window.c
void ft_window(t_game *game);
void ft_wall(t_game *game);

// hook.c
int	key_hook(int keycode, t_game *game);
#endif