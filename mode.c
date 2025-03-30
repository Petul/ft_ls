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
	if (++i && (statbuf.st_mode & S_IRUSR))
		fields->mode[i] = 'r';
	if (++i && (statbuf.st_mode & S_IWUSR))
		fields->mode[i] = 'w';
	if (++i && (statbuf.st_mode & S_IXUSR))
		fields->mode[i] = 'x';
	if (++i && (statbuf.st_mode & S_IRGRP))
		fields->mode[i] = 'r';
	if (++i && (statbuf.st_mode & S_IWGRP))
		fields->mode[i] = 'w';
	if (++i && (statbuf.st_mode & S_IXGRP))
		fields->mode[i] = 'x';
	if (++i && (statbuf.st_mode & S_IROTH))
		fields->mode[i] = 'r';
	if (++i && (statbuf.st_mode & S_IWOTH))
		fields->mode[i] = 'w';
	if (++i && (statbuf.st_mode & S_IXOTH))
		fields->mode[i] = 'x';
}
