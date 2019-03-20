/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mino.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:54:06 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 16:59:06 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		*minoxy(char **brd, int side, int xy[2], int pc)
{
	xy[Y] = -1;
	xy[X] = -1;
	while (xy[Y]++ < side)
		while (xy[X]++ < side)
			if (brd[xy[Y]][xy[X]] == pc + 'A')
				return (xy);
	return (xy);
}

int		mino_width(int min[26][4][2], int pc)
{
	int i;
	int maxi;
	int mini;

	i = 0;
	maxi = min[pc][i][X];
	mini = min[pc][i][X];
	while (i < 4)
	{
		if (min[pc][i][X] < mini)
			mini = min[pc][i][X];
		if (min[pc][i][X] > maxi)
			maxi = min[pc][i][X];
		i++;
	}
	return (maxi - mini + 1);
}

int		mino_height(int min[26][4][2], int pc)
{
	int i;
	int maxi;
	int mini;

	i = 0;
	maxi = min[pc][i][Y];
	mini = min[pc][i][Y];
	while (i < 4)
	{
		if (min[pc][i][Y] < mini)
			mini = min[pc][i][Y];
		if (min[pc][i][Y] > maxi)
			maxi = min[pc][i][Y];
		i++;
	}
	return (maxi - mini + 1);
}
