/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:09:48 by pleander          #+#    #+#             */
/*   Updated: 2025/04/01 22:26:18 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include "ft_ls.h"
#include "memlist.h"

void get_uid(t_fields *fields, int uid)
{
	struct passwd *pw;

	pw = getpwuid(uid);
	if (pw)
	{
		fields->owner = ft_strdup(pw->pw_name);
		if (!fields->owner)
			error_exit("ft_strdup");
		memlist_add(fields->owner);
	}
	else
	{
		fields->owner = ft_itoa(uid);
		if (!fields->owner)
			error_exit("ft_itoa");
		memlist_add(fields->owner);
	}
}

void get_gid(t_fields *fields, int uid)
{
	struct group *gr;

	gr = getgrgid(uid);
	if (gr)
	{
		fields->group = ft_strdup(gr->gr_name);
		if (!fields->group)
			error_exit("ft_strdup");
		memlist_add(fields->group);
	}
	else
	{
		fields->group = ft_itoa(uid);
		if (!fields->group)
			error_exit("ft_itoa");
		memlist_add(fields->group);
	}
}
