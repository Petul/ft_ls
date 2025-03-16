/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:04:12 by pleander          #+#    #+#             */
/*   Updated: 2025/03/16 13:03:05 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "memlist.h"
#include "ft_ls.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <dirent.h>

static void read_dir(DIR *d, t_list **dirc)
{
	t_list			*new;
	char			*name;
	struct dirent	*drnt;

	drnt = readdir(d);
	while (drnt)
	{
		name = ft_strdup(drnt->d_name);
		if (!name)
			error_exit("ft_strdup");
		if (!memlist_add(name))
			error_exit("memlist_add");
		new = ft_lstnew(name);
		if (!memlist_add(new))
			error_exit("memlist_add");
		ft_lstadd_back(dirc, new);
		drnt = readdir(d);
	}
}

void print_list(void *fname)
{
	ft_printf("%s\n", (char *)fname);
}

int	ft_ls(char *path, t_config *config, int recursive)
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
	ft_lstiter(*dirc, &print_list);
	return (0);
}

