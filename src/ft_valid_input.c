/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:37:58 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 12:38:26 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	loopval(t_m *m, t_v *v)
{
	while (++(v->a) < 4)
	{
		if (((m->min[v->i][v->bk][0] - 1) == (m->min[v->i][v->a][0]))
		&& ((m->min[v->i][v->bk][1]) == (m->min[v->i][v->a][1])))
			v->cnt++;
		if (((m->min[v->i][v->bk][0] + 1) == (m->min[v->i][v->a][0])) &&
		((m->min[v->i][v->bk][1]) == (m->min[v->i][v->a][1])))
			v->cnt++;
		if (((m->min[v->i][v->bk][1] - 1) == (m->min[v->i][v->a][1])) &&
		((m->min[v->i][v->bk][0]) == (m->min[v->i][v->a][0])))
			v->cnt++;
		if (((m->min[v->i][v->bk][1] + 1) == (m->min[v->i][v->a][1])) &&
		((m->min[v->i][v->bk][0]) == (m->min[v->i][v->a][0])))
			v->cnt++;
	}
}

int		ft_valid_input(t_m *m)
{
	t_v v;

	v.i = -1;
	v.bk = -1;
	v.a = -1;
	v.cnt = 0;
	while (v.i++ < m->nbminos)
	{
		while (++(v.bk) < 4)
		{
			loopval(m, &v);
			v.a = -1;
		}
		v.bk = -1;
		if (v.cnt != 6 && v.cnt != 8)
			return (0);
		v.cnt = 0;
	}
	return (1);
}
