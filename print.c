/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:22:56 by pleander          #+#    #+#             */
/*   Updated: 2025/04/13 22:08:24 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"
#include "time.h"
#include "memlist.h"

static void print_fw(char *str, int fw)
{
	int		len;
	char	*fstr;

	len = ft_snprintf(NULL, 0, "%%%ds ", fw);
	fstr = reserve(len + 1);
	if (!fstr)
		error_exit("reserve");
	ft_snprintf(fstr, len + 1, "%%%ds ", fw);
	ft_printf(fstr, str);
	release(fstr);
}

static void print_time(t_fields *fields, t_totals *totals)
{
	time_t	t;
	char	*tstr;
	char	*year;

	t = time(NULL);
	tstr = ctime(&t);
	year = get_column(tstr, 4);
	print_fw(fields->month, totals->fw_month);
	print_fw(fields->day, totals->fw_day);
	if (!ft_strncmp(year, fields->year, 4))
		print_fw(fields->time, totals->fw_time);
	else
		print_fw(fields->year, totals->fw_year);
}

static void	print_fields(t_fields *fields, t_totals *totals, t_config *config)
{
	if (config->fields & FIELDS_BLOCKS)
	 	print_fw(fields->blocks, totals->fw_blocks);
	if (config->fields & FIELDS_MODE)
		print_fw(fields->mode, totals->fw_mode);
	if (config->fields & FIELDS_COUNT)
		print_fw(fields->hard_links, totals->fw_hard_links);
	if (config->fields & FIELDS_OWNER)
		print_fw(fields->owner, totals->fw_owner);
	if (config->fields & FIELDS_GROUP)
		print_fw(fields->group, totals->fw_group);
	if (config->fields & FIELDS_SIZE)
		print_fw(fields->size, totals->fw_size);
	if (config->fields & FIELDS_TIME)
		print_time(fields, totals);
	if (config->fields & FIELDS_FILENAME)
		ft_printf(fields->filename);
	ft_printf("\n");
}

void print_list(t_list **dirc, t_config *config)
{
	t_list		*cur;
	t_totals	totals;

	if (!dirc || !*dirc)
		return;
	calc_totals(*dirc, &totals);
	cur = *dirc;
	if (config->other & OTHER_TOTAL_BLOCKS)
		ft_printf("total %d\n", totals.total_blocks);
	while (cur)
	{
 		print_fields((t_fields *)cur->content, &totals, config);
		cur = cur->next;
	}
}
