/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:00:51 by ariard            #+#    #+#             */
/*   Updated: 2016/11/11 21:48:38 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	size_t	n;

	n = ft_strlen(little);
	if (*little == 0)
		return (char *)(big);
	while (*big != 0)
	{
		if (ft_strncmp(big, little, n) == 0)
			return (char *)(big);
		big++;
	}
	return (NULL);
}
