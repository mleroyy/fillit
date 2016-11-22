/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:10:26 by ariard            #+#    #+#             */
/*   Updated: 2016/11/11 21:47:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*new;
	char		*tmp;

	if (!s || !f)
		return (NULL);
	new = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	tmp = new;
	while (*s)
	{
		*new = (*f)(*s);
		new++;
		s++;
	}
	*new = '\0';
	return (tmp);
}
