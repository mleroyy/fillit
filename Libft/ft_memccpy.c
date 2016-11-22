/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:16:03 by ariard            #+#    #+#             */
/*   Updated: 2016/11/11 21:43:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	const char		*p2;

	p1 = dst;
	p2 = src;
	while (n--)
	{
		if (c == *p2)
		{
			*p1++ = *p2++;
			return ((void *)p1);
		}
		*p1++ = *p2++;
	}
	return (NULL);
}
