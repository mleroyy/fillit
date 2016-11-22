/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_tetra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:30:10 by ariard            #+#    #+#             */
/*   Updated: 2016/11/19 17:21:11 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_put_abs(t_tetra *tetra)
{
	int				subx;
	int				suby;

	subx = 0;
	suby = 0;
	while (tetra->shape[0].x != 0)
	{
		tetra->shape[0].x = tetra->shape[0].x - 1;
		subx++;
	}
	tetra->shape[1].x = tetra->shape[1].x - subx;
	tetra->shape[2].x = tetra->shape[2].x - subx;
	tetra->shape[3].x = tetra->shape[3].x - subx;
	while (tetra->shape[0].y != 0)
	{
		tetra->shape[0].y = tetra->shape[0].y - 1;
		suby++;
	}
	tetra->shape[1].y = tetra->shape[1].y - suby;
	tetra->shape[2].y = tetra->shape[2].y - suby;
	tetra->shape[3].y = tetra->shape[3].y - suby;
}

static t_tetra		*ft_create_one(char *s, size_t x, size_t y, int j)
{
	t_tetra			*tetra;
	size_t			i;

	i = 0;
	if (!(tetra = (t_tetra *)malloc(sizeof(t_tetra))))
		return (0);
	while (i != 4)
	{
		if (*s == 35)
		{
			tetra->shape[i].x = x;
			tetra->shape[i].y = y;
			i++;
		}
		if (*s == 10 && (*(s - 1) == 35 || *(s - 1) == 46))
		{
			y++;
			x = 0;
		}
		s++;
		x++;
	}
	tetra->print = 'A' + j;
	ft_put_abs(tetra);
	return (tetra);
}

t_tetra				**ft_generate(char *s, unsigned long nbr)
{
	t_tetra			**tab;
	size_t			x;
	size_t			y;
	int				first;
	int				i;

	if (!(tab = (t_tetra **)malloc(sizeof(t_tetra *) * nbr)))
		return (0);
	first = 0;
	i = 0;
	x = 1;
	y = 1;
	while (*s)
	{
		if ((*(s - 1) == 10 && *(s - 2) == 10) || first++ == 0)
		{
			if (!(tab[i] = (t_tetra *)malloc(sizeof(t_tetra))))
				return (0);
			tab[i] = ft_create_one(s, x, y, i);
			i++;
		}
		s++;
	}
	return (tab);
}
