/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:51:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 17:15:39 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		setside(int nbminos)
{
	int side;

	side = 2;
	while ((side * side) < (4 * nbminos))
		side++;
	return (side);
}

char	**setboard(int side)
{
	char	**brd;
	int		i;
	int		a;

	i = -1;
	a = -1;
	if (!(brd = malloc(sizeof(char*) * (side + 1))))
		return (0);
	while (++i <= side)
	{
		if (!(brd[i] = malloc(sizeof(char) * (side + 1))))
			return (0);
		while (++a < side)
			brd[i][a] = '.';
		a = -1;
		brd[i][side] = '\0';
	}
	return (brd);
}

void	resetboard(int side, char **brd)
{
	int i;

	i = -1;
	while (++i < side)
	{
		free(brd[i]);
		brd[i] = NULL;
	}
	free(brd);
	brd = NULL;
}
