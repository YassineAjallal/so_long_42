/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:24:46 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/04 14:45:46 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>


// get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *save);
char	*ft_copy(char *save);
char	*ft_getnews(char *save);

// so_long

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
#endif