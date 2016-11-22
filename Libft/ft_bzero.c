/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:13:22 by ariard            #+#    #+#             */
/*   Updated: 2016/11/21 13:24:58 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p = '\0';
		p++;
	}
}
