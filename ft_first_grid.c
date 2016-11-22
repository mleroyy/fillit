/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:17:19 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/20 11:19:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_only_fries(t_tetra **tetra, t_info *info)
{
	int		i;
	int		ok;

	ok = 1;
	i = 0;
	while (i < info->nb)
	{
		if ((tetra[i]->shape[0].x != 0)
			|| (tetra[i]->shape[1].x != 0)
			|| (tetra[i]->shape[2].x != 0)
			|| (tetra[i]->shape[3].x != 0))
			return (0);
		i++;
	}
	info->fries = i;
	return (1);
}

void	ft_min_size(t_tetra **tetra, t_info *info)
{
	int			i;

	i = 0;
	if ((ft_only_fries(tetra, info) == 1) && (info->nb <= 8))
	{
		info->size = info->fries;
	}
	else
	{
		while ((i * i) < (info->nb * 4))
			i++;
		info->size = i;
	}
}

char	**ft_square(t_info *info)
{
	int		i;
	char	**square;

	i = 0;
	if ((square = (char **)malloc(sizeof(char *) * info->size)) == NULL)
		return (NULL);
	while (i < info->size)
	{
		if ((square[i] = ft_memalloc(info->size)) == NULL)
			return (NULL);
		ft_memset(square[i], 46, info->size);
		square[i][info->size] = '\0';
		i++;
	}
	return (square);
}

void	ft_print_square(char **square, t_info *info)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < info->size)
	{
		ft_putstr(square[i]);
		ft_putchar('\n');
		i++;
	}
}
