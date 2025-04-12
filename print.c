/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:22:56 by pleander          #+#    #+#             */
/*   Updated: 2025/04/02 21:05:43 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"


static void	print_fields(t_fields *fields, t_config *config)
{
	if (config->fields & FIELDS_MODE)
		ft_printf("%s ", fields->mode);
	if (config->fields & FIELDS_COUNT)
		ft_printf("%s ", fields->hard_links);
	if (config->fields & FIELDS_OWNER)
		ft_printf("%s ", fields->owner);
	if (config->fields & FIELDS_GROUP)
		ft_printf("%s ", fields->group);
	if (config->fields & FIELDS_SIZE)
		ft_printf("%s ", fields->size);
	if (config->fields & FIELDS_TIME)
		ft_printf("%s ", fields->time);
	if (config->fields & FIELDS_FILENAME)
		ft_printf("%s ", fields->filename);
	ft_printf("\n");
}

static void print_file(t_fields *fields, t_config *config)
{
	if (!ft_strcmp(fields->filename, ".") || !ft_strcmp(fields->filename, ".."))
	{
		if (config->files & FILES_SPECIAL)
			print_fields(fields, config);
		else
			return;
	}
	else if (fields->filename[0] == '.')
	{
		if (config->files & FILES_HIDDEN)
			print_fields(fields, config);
		else
			return;
	}
	else
	{
		print_fields(fields, config);
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
		print_file((t_fields *)cur->content, config);
		cur = cur->next;
	}
}
