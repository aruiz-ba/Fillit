/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkplc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:49:17 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 16:50:06 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		isout(int xy[2], int side, int pc, int min[26][4][2])
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if ((((min[pc][i][X]) + xy[X]) >= side)
			|| (((min[pc][i][Y]) + xy[Y]) >= side))
			return (1);
	}
	return (0);
}

int		checkpc(t_m *m, char **brd, int pc, int xy[2])
{
	int bq;

	bq = 0;
	if (isout(xy, m->side, pc, m->min))
	{
		ft_putstr("outside parameters\n");
		return (0);
	}
	while (bq < 4)
	{
		if (!(brd[m->min[pc][bq][Y] + xy[Y]][m->min[pc][bq][X] + xy[X]] == '.'))
			break ;
		if (bq == 3)
			return (1);
		bq++;
	}
	return (0);
}
