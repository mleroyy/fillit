/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:54:04 by ariard            #+#    #+#             */
/*   Updated: 2016/11/11 21:42:36 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst || !del)
		return ;
	tmp = *alst;
	(*del)(tmp->content, tmp->content_size);
	free(*alst);
	*alst = NULL;
}
