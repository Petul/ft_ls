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
