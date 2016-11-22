/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 20:04:46 by ariard            #+#    #+#             */
/*   Updated: 2016/11/19 20:52:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_check_layout_block(char *s, int block)
{
	if (((*(s + 1) == 35 || *(s + 5) == 35) && block < 3) || (((*(s + 4) == 35
		&& *(s - 1) == 35) || (*(s + 3) == 35 && *(s - 2) == 35)) && (block == 1
			|| block == 2)) || ((*(s - 1) == 35 || *(s - 5) == 35)
				&& block == 3))
		return (1);
	return (0);
}

static int			ft_check_pos_block(char *s, size_t x, size_t y, int block)
{
	block = 0;
	while (y % 5 != 0 && block < 5)
	{
		if (*s == 35)
		{
			if (ft_check_layout_block(s, block))
				block++;
			else
				return (1);
		}
		if (x == 5 && *s == 10)
		{
			x = 1;
			y++;
			s++;
		}
		else if (*s++)
			x++;
	}
	if (block != 4)
		return (1);
	return (0);
}

static int			ft_check_block(char *s, size_t x, size_t y)
{
	int				block;

	block = 0;
	while (*s)
	{
		if (*s == 35)
			block++;
		if (block == 1)
		{
			if (ft_check_pos_block(s, x, y, block))
				return (1);
			block++;
		}
		if (y % 5 == 0)
			block = 0;
		if ((x == 5 && *s == 10) || (y % 5 == 0 && *s == 10))
		{
			x = 1;
			y++;
			s++;
		}
		else if (*s++)
			x++;
	}
	return (0);
}

static int			ft_check_files(char *s, size_t x, size_t y)
{
	if (*s != 10 && *s != 35 && *s != 46)
		return (1);
	if (x % 5 == 0 && *s != 10)
		return (1);
	if (y > 129)
		return (1);
	if (y % 5 == 0 && ((*s != 10) || (*(s + 1) != 35 && *(s + 1) != 46)))
		return (1);
	return (0);
}

int					ft_check_all(char *s)
{
	size_t			x;
	size_t			y;
	char			*tmp;

	x = 1;
	y = 1;
	tmp = s;
	while (*s)
	{
		if (ft_check_files(s, x, y))
			return (1);
		if ((x == 5 && *s == 10) || (y % 5 == 0 && *s == 10))
		{
			x = 1;
			y++;
			s++;
		}
		else if (*s++)
			x++;
	}
	x = 1;
	y = 1;
	if (ft_check_block(tmp, x, y))
		return (1);
	return (0);
}
