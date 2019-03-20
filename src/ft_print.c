/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:59:55 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 17:04:32 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	printboard(char **board)
{
	int i;
	int side;

	i = -1;
	side = ft_strlen(board[0]);
	while (++i < side)
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
	}
	return (0);
}
