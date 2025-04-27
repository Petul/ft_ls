/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:26:18 by pleander          #+#    #+#             */
/*   Updated: 2025/04/02 20:36:02 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include "memlist.h"

void get_size(t_fields *fields, int size)
{
	fields->size = ft_itoa(size);
	if (!fields->size)
		error_exit("ft_itoa");
	memlist_add(fields->size);
}

// stat reports blocks in 512 bytes but ls reportes
// number of 1024 bytes blocks, so dividing by 2
// should produce correct result
void get_blocks(t_fields *fields, int blocks)
{
	fields->blocks_int = blocks / 2;
	fields->blocks = ft_itoa(fields->blocks_int);
	if (!fields->blocks)
		error_exit("ft_itoa");
	memlist_add(fields->blocks);
}
