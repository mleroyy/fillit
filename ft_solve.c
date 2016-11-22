/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:07:07 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/20 12:27:19 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_erase_it(char **square, t_tetra **tetra, t_info *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < info->size)
	{
		while (j < info->size)
		{
			if (square[i][j] == tetra[info->count]->print)
			{
				square[i][j] = '.';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_put_it(char **square, t_tetra **tetra, t_info *info)
{
	square[info->i + tetra[info->count]->shape[0].y][info->j
		+ tetra[info->count]->shape[0].x] = tetra[info->count]->print;
	square[info->i + tetra[info->count]->shape[1].y][info->j
		+ tetra[info->count]->shape[1].x] = tetra[info->count]->print;
	square[info->i + tetra[info->count]->shape[2].y][info->j
		+ tetra[info->count]->shape[2].x] = tetra[info->count]->print;
	square[info->i + tetra[info->count]->shape[3].y][info->j
		+ tetra[info->count]->shape[3].x] = tetra[info->count]->print;
}

int		ft_can_i_put(char **square, t_tetra **tetra, t_info *info)
{
	if (ft_is_in_square(tetra, info))
		return (0);
	if ((square[info->i + tetra[info->count]->shape[0].y][info->j
		+ tetra[info->count]->shape[0].x] == '.') && (square[info->i
			+ tetra[info->count]->shape[1].y][info->j
				+ tetra[info->count]->shape[1].x] == '.') && (square[info->i
					+ tetra[info->count]->shape[2].y][info->j
						+ tetra[info->count]->shape[2].x] == '.')
							&& (square[info->i
								+ tetra[info->count]->shape[3].y][info->j
									+ tetra[info->count]->shape[3].x] == '.'))
		return (1);
	return (0);
}

int		ft_return_back(char **square, t_tetra **tetra, t_info *info)
{
	info->count -= 1;
	if (info->count < 0)
		return (1);
	ft_erase_it(square, tetra, info);
	if (tetra[info->count]->cj < info->size)
		tetra[info->count]->cj += 1;
	else if (tetra[info->count]->cj >= (info->size - 1)
			&& (tetra[info->count]->ci == (info->size - 1)))
	{
		tetra[info->count]->cj = 0;
		tetra[info->count]->ci += 1;
	}
	info->j = tetra[info->count]->cj;
	info->i = tetra[info->count]->ci;
	return (0);
}

int		ft_solve(char **square, t_tetra **tetra, t_info *info)
{
	while (info->count < info->nb)
	{
		if (ft_can_i_put(square, tetra, info) == 1)
		{
			ft_put_it(square, tetra, info);
			tetra[info->count]->ci = (info->i) + tetra[info->count]->shape[0].y;
			tetra[info->count]->cj = (info->j) + tetra[info->count]->shape[0].x;
			info->i = 0;
			info->j = 0;
			info->count += 1;
		}
		else if (info->j < info->size - 1)
			info->j += 1;
		else if ((info->j >= info->size - 1) && (info->i != info->size - 1))
		{
			info->j = 0;
			info->i += 1;
		}
		else if ((info->j == info->size - 1) && (info->i == info->size - 1))
			if (ft_return_back(square, tetra, info))
				return (0);
	}
	return (1);
}
