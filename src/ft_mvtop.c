/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvtop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:28:33 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 12:31:56 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	ft_move_minos(t_m *m)
{
	int		i;
	int		ymv;
	int		xmv;
	int		pcn;

	i = -1;
	ymv = 0;
	xmv = 5;
	pcn = -1;
	while (++pcn <= m->nbminos)
	{
		ymv = m->min[pcn][0][1];
		while (++i < 4)
		{
			m->min[pcn][i][1] = m->min[pcn][i][1] - ymv;
			if (xmv > m->min[pcn][i][0])
				xmv = m->min[pcn][i][0];
		}
		i = -1;
		while (++i < 4)
			m->min[pcn][i][0] = m->min[pcn][i][0] - xmv;
		i = -1;
		xmv = 5;
	}
	return (0);
}
