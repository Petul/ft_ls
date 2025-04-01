/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:37:16 by pleander          #+#    #+#             */
/*   Updated: 2025/04/01 18:49:10 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "memlist.h"

void	get_hard_link_count(t_fields *fields, struct stat *statbuf)
{
	char *n_links;

	n_links = ft_itoa((int)statbuf->st_nlink);
	if (!n_links)
		error_exit("ft_itoa");
	memlist_add(n_links);
	fields->hard_links = n_links;
}
