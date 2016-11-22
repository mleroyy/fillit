/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:25:45 by ariard            #+#    #+#             */
/*   Updated: 2016/11/21 13:50:45 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*p;

	p = 0;
	p = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size + 1);
	return (p);
}
