/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:57:53 by pleander          #+#    #+#             */
/*   Updated: 2025/04/13 21:19:14 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void calc_totals(t_list *dirc, t_totals *totals)
{
	t_fields *field;

	ft_bzero(totals, sizeof(t_totals));
	while (dirc)
	{
		field = (t_fields *)dirc->content;
		totals->total_blocks += field->blocks_int;
		if (ft_strlen(field->blocks) > (size_t)totals->fw_blocks)
			totals->fw_blocks = ft_strlen(field->blocks);
		if (ft_strlen(field->mode) > (size_t)totals->fw_mode)
			totals->fw_mode = ft_strlen(field->mode);
		if (ft_strlen(field->hard_links) > (size_t)totals->fw_hard_links)
			totals->fw_hard_links = ft_strlen(field->hard_links);
		if (ft_strlen(field->owner) > (size_t)totals->fw_owner)
			totals->fw_owner = ft_strlen(field->owner);
		if (ft_strlen(field->group) > (size_t)totals->fw_group)
			totals->fw_group = ft_strlen(field->group);
		if (ft_strlen(field->size) > (size_t)totals->fw_size)
			totals->fw_size = ft_strlen(field->size);
		if (ft_strlen(field->month) > (size_t)totals->fw_month)
			totals->fw_month = ft_strlen(field->month);
		if (ft_strlen(field->day) > (size_t)totals->fw_day)
			totals->fw_day = ft_strlen(field->day);
		if (ft_strlen(field->time) > (size_t)totals->fw_time)
			totals->fw_time = ft_strlen(field->time);
		if (ft_strlen(field->year) > (size_t)totals->fw_year)
			totals->fw_year = ft_strlen(field->year);
		if (ft_strlen(field->filename) > (size_t)totals->fw_filename)
			totals->fw_filename = ft_strlen(field->filename);
		dirc = dirc->next;
	}
}
