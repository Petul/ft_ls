/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_dirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:25:43 by pleander          #+#    #+#             */
/*   Updated: 2025/05/08 21:29:27 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_printf.h"
#include "libft.h"
#include "ft_ls.h"
#include "memlist.h"

static int	include_dir(t_dirent *drnt, t_config *config)
{

	if (!ft_strcmp(drnt->d_name, ".") || !ft_strcmp(drnt->d_name, ".."))
		return (0);
	if (drnt->d_name[0] == '.' && !(config->files & FILES_HIDDEN))
		return (0);
	return (1);
}
static void recurse_dirs(t_list *dirs, char *path, t_config *config)
{
	t_list		*new;
	t_dirent	*drnt;
	DIR			*d;
	char		*new_path;
	int			size;

	d = opendir(path);
	drnt = readdir(d); // Todo: handle closedir on error
	while (drnt)
	{
		if (include_dir(drnt, config))
		{
			if (drnt->d_type == DT_DIR)
			{
				size = ft_strlen(path) + ft_strlen(drnt->d_name) + 2;
				new_path = reserve(size);
				if (!new_path)
					error_exit("reserve");
				ft_snprintf(new_path, size, "%s/%s", path, drnt->d_name);
				new = ft_lstnew(new_path);
				ft_lstadd_back(&dirs, new);
				recurse_dirs(dirs, new_path, config);
			}
		}
		drnt = readdir(d);
	}
}

void add_dirs_recursively(t_list *dirs, t_config *config)
{
	int		len;
	t_list	*cur;

	len = ft_lstsize(dirs);
	if (len == 0)
		return;
	cur = dirs;
	while (len > 0)
	{
		recurse_dirs(cur, cur->content, config);
		len--;
	}
}
