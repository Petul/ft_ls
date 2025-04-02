/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:04:12 by pleander          #+#    #+#             */
/*   Updated: 2025/04/02 20:50:47 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include "libft.h"
#include "memlist.h"
#include "ft_printf.h"
#include "ft_ls.h"

static char *make_fpath(char *dirpath, const t_dirent *f)
{
	int		len;
	char	*fpath;

	len = ft_strlen(dirpath) + ft_strlen(f->d_name) + 2;
	fpath = reserve(len);
	if (!fpath)
		error_exit("reserve");
	if (ft_snprintf(fpath, len, "%s/%s", dirpath, f->d_name) < 0)
		error_exit("ft_snprintf");
	return (fpath);
}

static void fill_fields(t_fields *fields, char *dirpath, t_dirent *dirent, t_config *config)
{
	char *fpath;
	struct stat statbuf;

	fpath = make_fpath(dirpath, dirent);
	fields->filename = ft_strdup(dirent->d_name);
	if (!fields->filename)
		error_exit("ft_strdup");
	memlist_add(fields->filename);
	if (lstat(fpath, &statbuf) < 0)
		error_exit("lstat");
	get_mode(fields, &statbuf);
	get_hard_link_count(fields, &statbuf);
	get_uid(fields, statbuf.st_uid);
	get_gid(fields, statbuf.st_gid);
	get_size(fields, statbuf.st_size);
	get_mod_time(fields, &statbuf.st_mtim.tv_sec);
}

static void read_dir(char *path, t_list **dirc, t_config *config)
{
	t_list		*new;
	t_fields	*fields;
	t_dirent	*drnt;
	DIR			*d;

	d = opendir(path);
	drnt = readdir(d); // Todo: handle closedir on error
	while (drnt)
	{
		fields = reserve(sizeof(t_fields));
		if (!fields)
			error_exit("reserve");
		fill_fields(fields, path, drnt, config);
		new = ft_lstnew(fields);
		if (!new)
			error_exit("ft_lstnew");
		if (!memlist_add(new))
			error_exit("memlist_add");
		ft_lstadd_back(dirc, new);
		drnt = readdir(d);
	}
	closedir(d);
}

int	ft_ls(char *path, t_config *config)
{
	t_list	**dirc;

	dirc = creserve(1, sizeof(t_list *));
	if (!dirc)
		error_exit("creserve");
	read_dir(path, dirc, config);
	sort_files(dirc, config);
	print_list(dirc, config);
	return (0);
}

