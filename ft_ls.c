/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:04:12 by pleander          #+#    #+#             */
/*   Updated: 2025/03/15 14:40:31 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <dirent.h>

int	ft_ls(char *path, t_config *config, int recursive)
{
	DIR *d;
	struct dirent *drnt;

	d = opendir(path);
	drnt = readdir(d);
	while (drnt)
	{
		ft_printf("%s\n", drnt->d_name);
		drnt = readdir(d);
	}
	ft_printf("\n");
	return (0);
}

