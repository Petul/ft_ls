/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:22:56 by pleander          #+#    #+#             */
/*   Updated: 2025/03/28 08:25:32 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_ls.h"
#include "libft.h"
#include "memlist.h"
#include "ft_printf.h"

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

static void	print_fields(t_fields *fields, t_config *config)
{
	if (config->fields & FIELDS_MODE)
		ft_printf("%s ", fields->mode);
	if (config->fields & FIELDS_FILENAME)
		ft_printf("%s", fields->filename);
	ft_printf("\n");
}

static void make_fields(char *dirpath, const t_dirent *f, t_config *config)
{
	t_fields	fields;
	char		*fpath;

	fields.filename = ft_strdup(f->d_name);
	if (!fields.filename)
		error_exit("ft_strdup");
	memlist_add(fields.filename);
	fpath = make_fpath(dirpath, f);
	if (config->fields & FIELDS_MODE)
		get_mode(&fields, fpath);
	print_fields(&fields, config);
	
	if (config->fields & FIELDS_MODE)
		release(fields.mode);
}

static void print_file(char *dirpath, const t_dirent *f, t_config *config)
{
	if (!ft_strcmp(f->d_name, ".") || !ft_strcmp(f->d_name, ".."))
	{
		if (config->files & FILES_SPECIAL)
			make_fields(dirpath, f, config);
		else
			return;
	}
	else if (f->d_name[0] == '.')
	{
		if (config->files & FILES_HIDDEN)
			make_fields(dirpath, f, config);
		else
			return;
	}
	else
	{
		make_fields(dirpath, f, config);
	}
}
// static void print_file(char *dirpath, const t_dirent *f, t_config *config)
// {
// 	if (!ft_strcmp(f->d_name, ".") || !ft_strcmp(f->d_name, ".."))
// 	{
// 		if (config->files & FILES_SPECIAL)
// 			ft_printf("%s\n", f->d_name);
// 		else
// 			return;
// 	}
// 	else if (f->d_name[0] == '.')
// 	{
// 		if (config->files & FILES_HIDDEN)
// 			ft_printf("%s\n", f->d_name);
// 		else
// 			return;
// 	}
// 	else
// 	{
// 		ft_printf("%s\n", f->d_name);
// 	}
// }

void print_list(char *dirpath, t_list **dirc, t_config *config)
{
	t_list *cur;

	if (!dirc || !*dirc)
		return;
	cur = *dirc;
	while (cur)
	{
		print_file(dirpath, (t_dirent *)cur->content, config);

		cur = cur->next;
	}
}
