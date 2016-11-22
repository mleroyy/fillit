/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:25:32 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/21 13:33:09 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_is_in_square(t_tetra **tetra, t_info *info)
{
	if (((0 > (info->j + tetra[info->count]->shape[0].x))
		|| (info->size - 1 < (info->j + tetra[info->count]->shape[0].x)))
			|| ((0 > (info->j + tetra[info->count]->shape[1].x))
				|| (info->size - 1 < (info->j
					+ tetra[info->count]->shape[1].x))))
		return (1);
	if (((0 > (info->j + tetra[info->count]->shape[2].x))
		|| (info->size - 1 < (info->j + tetra[info->count]->shape[2].x)))
			|| ((0 > (info->j + tetra[info->count]->shape[3].x))
				|| (info->size - 1 < (info->j
					+ tetra[info->count]->shape[3].x))))
		return (1);
	if (((0 > (info->i + tetra[info->count]->shape[0].y))
		|| (info->size - 1 < (info->i + tetra[info->count]->shape[0].y)))
			|| ((0 > (info->i + tetra[info->count]->shape[1].y))
				|| (info->size - 1 < (info->i +
					tetra[info->count]->shape[1].y))))
		return (1);
	if (((0 > (info->i + tetra[info->count]->shape[2].y))
		|| (info->size - 1 < (info->i + tetra[info->count]->shape[2].y)))
			|| ((0 > (info->i + tetra[info->count]->shape[3].y))
				|| (info->size - 1 < (info->i
					+ tetra[info->count]->shape[3].y))))
		return (1);
	return (0);
}

void			ft_set_info(t_info *info, char *s)
{
	info->i = 0;
	info->j = 0;
	info->count = 0;
	info->nb = ft_count_tetra(s) - 1;
}

int				ft_control(char *s)
{
	t_info		info;
	t_tetra		**tetra;
	char		**square;

	ft_set_info(&info, s);
	if ((tetra = ft_generate(s, info.nb + 1)) == NULL)
		return (0);
	ft_min_size(tetra, &info);
	square = ft_square(&info);
	if (square == NULL)
		return (0);
	while (ft_solve(square, tetra, &info) != 1)
	{
		ft_del_square(square, &info);
		info.size += 1;
		square = ft_square(&info);
		ft_set_info(&info, s);
	}
	ft_print_square(square, &info);
	return (1);
}

int				main(int argc, char **argv)
{
	char		*s;

	if (argc != 2)
	{
		ft_print_usage();
		return (1);
	}
	if (!(s = ft_read_tetra(argv[1])))
	{
		ft_print_error();
		return (1);
	}
	if (ft_control(s) == 0)
		return (1);
	return (0);
}
