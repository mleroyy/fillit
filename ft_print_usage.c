/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:35:40 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/19 20:41:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar_error(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_error(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putchar_error(str[i]);
		i++;
	}
}

void	ft_print_usage(void)
{
	ft_putstr_error("usage: ./fillit source_file\n");
}

void	ft_print_error(void)
{
	ft_putstr_error("error");
	ft_putchar(10);
}
