/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:59:21 by pleander          #+#    #+#             */
/*   Updated: 2025/03/16 13:14:41 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stddef.h>
#include "ft_ls.h"
#include "libft.h"

static int lexcmp(const struct dirent *f1, const struct dirent *f2)
{
	const char *s1 = f1->d_name;
	const char *s2 = f2->d_name;
	size_t	i;
	int c1;
	int c2;

	i = 0;
	c1 = ft_toupper(s1[i]);
	c2 = ft_toupper(s2[i]);
	while (c1 == c2 && c1)
	{
		i++;
		c1 = ft_toupper(s1[i]);
		c2 = ft_toupper(s2[i]);
	}
	return ((unsigned char)c1 - (unsigned char)c2);
}

void sort_files(t_list **files, t_config *config)
{
	ft_lstsort(files, &lexcmp);
}
