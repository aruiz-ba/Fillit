/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:07:02 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 12:27:08 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validchar(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		validbox(char *str, int y)
{
	if (ft_strlen(str) != 0 && y == 4)
		return (0);
	if (ft_strlen(str) == 0 && y == 4)
		return (1);
	if (ft_strlen(str) != 4)
		return (0);
	else
		return (1);
}

void	loop(t_m *m, t_parse *parse)
{
	while ((++(parse->x) <= 4 && parse->buff[parse->x]))
	{
		if (parse->buff[parse->x] == '#')
		{
			parse->bknum++;
			m->min[m->nbminos][parse->bknum][0] = parse->x;
			m->min[m->nbminos][parse->bknum][1] = parse->y;
		}
	}
}

int		ft_parse_file(t_m *m, char *root)
{
	t_parse parse;

	parse.y = -1;
	parse.x = -1;
	parse.i = -1;
	m->nbminos = -1;
	parse.bknum = -1;
	parse.fd = open(root, O_RDONLY);
	while (++(m->nbminos) < 26)
	{
		while (++(parse.y) <= 4)
		{
			if (get_next_line(parse.fd, &parse.buff) == 0)
				return (1);
			if (!validchar(parse.buff) || !validbox(parse.buff, parse.y))
				return (0);
			loop(m, &parse);
			parse.x = -1;
			if (parse.bknum > 3)
				return (0);
		}
		parse.y = -1;
		parse.bknum = -1;
	}
	return (-1);
}
