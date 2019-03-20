/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:17:04 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 17:19:17 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 1
# define MAX_SIDE 16
# define X 0
# define Y 1

typedef struct	s_m
{
	int			nbminos;
	int			min[26][4][2];
	int			side;
}				t_m;

typedef struct	s_parse
{
	int			fd;
	char		*buff;
	int			y;
	int			x;
	int			bknum;
	int			i;
}				t_parse;

typedef struct	s_v
{
	int			i;
	int			bk;
	int			a;
	int			cnt;
}				t_v;

typedef struct	s_print
{
	int			bl;
	int			x;
	int			y;
	int			i;
}				t_print;
int				ft_parse_file(t_m *m, char *argv);
int				ft_valid_input(t_m *m);
int				ft_move_minos(t_m *m);
int				biggerboard(t_m *m, char ***brd);
int				printboard (char **brd);

int				mino_height(int min[26][4][2], int pc);
int				mino_width(int min[26][4][2], int pc);
int				*minoxy(char **brd, int side, int xy[2], int pc);

void			resetboard(int side, char **brd);
char			**setboard(int side);
int				setside(int nbminos);

int				checkpc(t_m *m, char **brd, int pc, int xy[2]);
int				isout(int xy[2], int side, int pc, int min[26][4][2]);

int				removpc(char **brd, int side, int pc);
int				placepc(char **brd, int min[26][4][2], int pc, int xy[2]);
#endif
