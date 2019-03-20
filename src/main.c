/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:30:49 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/03/20 17:07:06 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_parseerr(void)
{
	ft_putstr("error");
	return (0);
}

int		ft_validinputerr(void)
{
	ft_putstr("error");
	return (0);
}

int		main(int argc, char **argv)
{
	char	**brd;
	t_m		m;

	if (argc != 2)
	{
		ft_putstr("too few arguments\n");
		return (0);
	}
	if (ft_parse_file(&m, argv[1]) <= 0)
		return (ft_parseerr());
	if (ft_valid_input(&m) <= 0)
		return (ft_validinputerr());
	ft_move_minos(&m);
	biggerboard(&m, &brd);
	printboard(brd);
}
