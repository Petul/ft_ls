/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:22:56 by pleander          #+#    #+#             */
/*   Updated: 2025/03/20 15:56:52 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"

static void print_file(const t_dirent *f, t_config *config)
{
	if (!ft_strcmp(f->d_name, ".") || !ft_strcmp(f->d_name, ".."))
	{
		if (config->files & FILES_SPECIAL)
			ft_printf("%s\n", f->d_name);
		else
			return;
	}
	else if (f->d_name[0] == '.')
	{
		if (config->files & FILES_HIDDEN)
			ft_printf("%s\n", f->d_name);
		else
			return;
	}
	else
	{
		ft_printf("%s\n", f->d_name);
	}
}

void print_list(t_list **dirc, t_config *config)
{
	t_list *cur;

	if (!dirc || !*dirc)
		return;
	cur = *dirc;
	while (cur)
	{
		print_file((t_dirent *)cur->content, config);

		cur = cur->next;
	}
}
