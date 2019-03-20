/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:41:19 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 16:56:56 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		placepc(char **brd, int min[26][4][2], int pc, int xy[2])
{
	int bk;

	bk = -1;
	while (++bk < 4)
		brd[min[pc][bk][Y] + xy[Y]][min[pc][bk][X] + xy[X]] = 65 + pc;
	return (0);
}

int		removpc(char **brd, int side, int pc)
{
	int y;
	int x;

	y = -1;
	x = -1;
	while (++y < side)
	{
		while (++x < side)
		{
			if (brd[y][x] == pc + 'A')
				brd[y][x] = '.';
		}
		x = -1;
	}
	return (0);
}
