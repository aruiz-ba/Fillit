/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:23:38 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 16:59:00 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		backtrack(t_m *m, int pc, char ***brd)
{
	int		xy[2];

	xy[Y] = 0;
	if (pc == m->nbminos)
		return (1);
	while (xy[Y] <= (m->side - mino_height(m->min, pc)))
	{
		xy[X] = 0;
		while (xy[X] <= (m->side - mino_width(m->min, pc)))
		{
			if (checkpc(m, *brd, pc, xy))
			{
				placepc(*brd, m->min, pc, xy);
				if (backtrack(m, pc + 1, brd))
					return (1);
				else
					removpc(*brd, m->side, pc);
			}
			xy[X]++;
		}
		xy[Y]++;
	}
	return (0);
}

int		biggerboard(t_m *m, char ***brd)
{
	int	pc;

	pc = 0;
	m->nbminos = m->nbminos + 1;
	m->side = setside(m->nbminos);
	while (m->side < MAX_SIDE)
	{
		*brd = setboard(m->side);
		if (backtrack(m, pc, brd))
			break ;
		++(m->side);
	}
	return (0);
}
