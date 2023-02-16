/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:24:46 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/15 16:07:44 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// includes
# include "./libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

// define
# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 5120
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 2880
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// struct
typedef struct s_coord
{
	int	i;
	int	j;
}	t_coord;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*coin;
	void	*wall;
	void	*door;
	void	*background;
	int		width;
	char	pdir;
	int		height;
	t_coord	*pcoord;
	t_coord	*ecoord;
	int		collect;
	int		exit;
	int		positions;
	int		mouves;

	int		line;
	int		len;
}	t_game;

// get_next_line.c
char	*get_next_line(int fd);
char	*ft_read(int fd, char *save);
char	*ft_copy(char *save);
char	*ft_getnews(char *save);

// so_long.c
void	arg_error(int ac, char **av);
void	map_check(t_game *game, char **av);
void	init(t_game *game, char **av);

// arrays.c
void	ft_free2d(char **str);
void	free_game(t_game *game);

// checkex.c
int		ft_checkex(char *file);

// destroy.c
void	destroy(t_game *game);
int		ondestroy(t_game *game);

// directions.c
void	right(t_game *game);
void	up(t_game *game);
void	left(t_game *game);
void	down(t_game *game);

// finish.c
void	finish(t_game *game, int i, int j);

// ft_strlennl.c
int		ft_strlennl(char *str);

// hooks.c
int		directions(int keycode, t_game *game);
void	ft_player(t_game *game, char pdir);

// images.c
int		fill_images(t_game *game);

// print.c
void	print(int fd, char *s, ...);

// readmap.c
int		numberline(char **map);
int		readfile(int fd);
char	**readmap(char *path);

// validmap.c
int		checklen(char **map);
int		isequal(char *line);
int		checkwall(char **map);
int		valid_char(char c);
int		checkchar(t_game *game);

// validpath.c
void	ft_replace(char **map);
void	ft_fill(char **map);
int		ft_checkvalid(char **map);

//  window.c
int		ft_window(t_game *game);
void	ft_put_image(t_game *game, int i, int j);
void	ft_images(t_game *game);
#endif