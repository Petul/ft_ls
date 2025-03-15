/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:47:21 by pleander          #+#    #+#             */
/*   Updated: 2025/03/15 21:08:16 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sorted(t_list *lst, int (*cmp)(void *, void *))
{
	while (lst->next)
	{
		if (cmp(lst->content, lst->next->content) > 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}


void	ft_lstsort(t_list **begin_list, int (*cmp)(void *, void *))
{
	t_list	*cur;
	void	*tmp;

	if (!begin_list || !*begin_list)
		return ;
	while (!is_sorted(*begin_list, cmp))
	{
		cur = *begin_list;
		while (cur && cur->next)
		{
			if (cmp(cur->content, cur->next->content) > 0)
			{
				tmp = cur->content;
				cur->content = cur->next->content;
				cur->next->content = tmp;
			}
			cur = cur->next;
		}
	}
}
