/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:59:21 by pleander          #+#    #+#             */
/*   Updated: 2025/03/20 16:07:17 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stddef.h>
#include "ft_ls.h"
#include "libft.h"

static char * remove_leading_dots(char *s)
{
	int i;

	i = 0;
	while (s[i] == '.')
	{
		i++;
	}
	if (s[i] == '\0')
		return s;
	return (s + i);
}

static int lexcmp(const t_dirent *f1, const t_dirent *f2)
{
	char	*s1;
	char	*s2;
	size_t	i;
	int c1;
	int c2;

	s1 = remove_leading_dots((char *)f1->d_name);
	s2 = remove_leading_dots((char *)f2->d_name);
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
