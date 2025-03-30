/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:36:53 by pleander          #+#    #+#             */
/*   Updated: 2025/03/27 21:25:43 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include "libft.h"
#include "memlist.h"
#include "ft_ls.h"

static void	get_user_modes(t_fields *fields, struct stat *statbuf, int pos)
{
	if (++pos && (statbuf->st_mode & S_IRUSR))
		fields->mode[pos] = 'r';
	if (++pos && (statbuf->st_mode & S_IWUSR))
		fields->mode[pos] = 'w';
	if (++pos && (statbuf->st_mode & S_IXUSR))
		fields->mode[pos] = 'x';
	if (++pos && (statbuf->st_mode & S_IRGRP))
		fields->mode[pos] = 'r';
	if (++pos && (statbuf->st_mode & S_IWGRP))
		fields->mode[pos] = 'w';
	if (++pos && (statbuf->st_mode & S_IXGRP))
		fields->mode[pos] = 'x';
	if (++pos && (statbuf->st_mode & S_IROTH))
		fields->mode[pos] = 'r';
	if (++pos && (statbuf->st_mode & S_IWOTH))
		fields->mode[pos] = 'w';
	if (++pos && (statbuf->st_mode & S_IXOTH))
		fields->mode[pos] = 'x';
}

static void	get_file_type(t_fields *fields, struct stat *statbuf, int pos)
{
	if (S_ISREG(statbuf->st_mode))
		fields->mode[pos] = '-';
	else if (S_ISDIR(statbuf->st_mode))
		fields->mode[pos] = 'd';
	else if (S_ISCHR(statbuf->st_mode))
		fields->mode[pos] = 'c';
	else if (S_ISBLK(statbuf->st_mode))
		fields->mode[pos] = 'b';
	else if (S_ISLNK(statbuf->st_mode))
		fields->mode[pos] = 'l';
	else if (S_ISSOCK(statbuf->st_mode))
		fields->mode[pos] = 's';
	else if (S_ISFIFO(statbuf->st_mode))
		fields->mode[pos] = 'p';
}

void	get_mode(t_fields *fields, char *fpath)
{
	struct	stat	statbuf;
	char			*mode_str;
	int				i;

	fields->mode = reserve(sizeof(char) * 11);
	if (!fields->mode)
		error_exit("reserve");
	i = 0;
	ft_memset(fields->mode, '-', 10);
	fields->mode[10] = '\0';
	if (lstat(fpath, &statbuf) < 0)
		error_exit("lstat");
	get_file_type(fields, &statbuf, i);
	get_user_modes(fields, &statbuf, i);
}
