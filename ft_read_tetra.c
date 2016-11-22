/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:21:40 by ariard            #+#    #+#             */
/*   Updated: 2016/11/20 12:23:38 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t				ft_count_tetra(char *s)
{
	size_t			x;
	size_t			y;
	size_t			i;

	i = 1;
	x = 1;
	y = 1;
	while (*s)
	{
		if (y % 5 == 0 && *s == 10)
			i++;
		if ((x == 5 && *s == 10) || (y % 5 == 0 && *s == 10))
		{
			x = 1;
			y++;
			s++;
		}
		else if (*s++)
			x++;
	}
	return (i + 1);
}

void				ft_del_square(char **square, t_info *info)
{
	int				i;

	i = 0;
	while (i < info->size)
	{
		free(square[i]);
		square[i] = NULL;
		i++;
	}
	free(square);
	square = NULL;
}

int					ft_one_struct_by_square(char *tmp)
{
	size_t			block;
	int				no_block_yet;
	size_t			nbr;

	nbr = ft_count_tetra(tmp) - 1;
	block = 0;
	no_block_yet = 1;
	while (*tmp)
	{
		if (*tmp == 35 && no_block_yet)
		{
			block++;
			no_block_yet--;
		}
		if (*tmp == 10 && *(tmp - 1) == 10)
			no_block_yet = 1;
		tmp++;
	}
	if (nbr == block)
		return (0);
	return (1);
}

char				*ft_read_tetra(char *files)
{
	int				fd;
	char			buf;
	char			*s;
	char			*tmp;
	size_t			index;

	s = ft_memalloc(545);
	ft_bzero(s, 545);
	index = 0;
	tmp = s;
	fd = open(files, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((read(fd, &buf, 1)) && index++ < 546)
		*s++ = buf;
	if (close(fd) == -1)
		return (NULL);
	if (ft_strlen(tmp) == 0)
		return (NULL);
	if (ft_one_struct_by_square(tmp))
		return (NULL);
	if (ft_check_all(tmp))
		return (NULL);
	return (tmp);
}
