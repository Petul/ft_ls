/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:04:12 by pleander          #+#    #+#             */
/*   Updated: 2025/03/20 16:01:09 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include "libft.h"
#include "memlist.h"
#include "ft_ls.h"

static void read_dir(DIR *d, t_list **dirc)
{
	t_list			*new;
	t_dirent	*drnt_copy;
	t_dirent	*drnt;

	drnt = readdir(d);
	while (drnt)
	{

		drnt_copy = reserve(sizeof(t_dirent));
		if (!drnt_copy)
			error_exit("reserve");
		ft_memcpy(drnt_copy, drnt, sizeof(t_dirent));
		new = ft_lstnew(drnt_copy);
		if (!new)
			error_exit("ft_lstnew");
		if (!memlist_add(new))
			error_exit("memlist_add");
		ft_lstadd_back(dirc, new);
		drnt = readdir(d);
	}
}

int	ft_ls(char *path, t_config *config)
{
	DIR		*d;
	t_list	**dirc;

	dirc = creserve(1, sizeof(t_list *));
	if (!dirc)
		error_exit("creserve");
	d = opendir(path);
	read_dir(d, dirc);
	closedir(d);
	sort_files(dirc, config);
	print_list(dirc, config);
	return (0);
}

