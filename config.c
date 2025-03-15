/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:42:35 by pleander          #+#    #+#             */
/*   Updated: 2025/03/14 16:08:39 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"

void	apply_default_config(t_config *c)
{
	ft_bzero(c, sizeof(t_config));
	c->fields |= FIELDS_FILENAME;
	c->time_type |= TT_CREATION_TIME;
	c->files |= FILES_REGULAR;
	c->list_type |= LIST_TYPE_LIST;
}

void print_config(t_config *c)
{
	//ft_printf("FIELDS:\n");
	ft_printf("FIELDS_MODE: %d\n", (c->fields & FIELDS_MODE) > 0);
	ft_printf("FIELDS_COUNT: %d\n", (c->fields & FIELDS_COUNT) > 0);
	ft_printf("FIELDS_OWNER: %d\n", (c->fields & FIELDS_OWNER) > 0);
	ft_printf("FIELDS_GROUP: %d\n", (c->fields & FIELDS_GROUP) > 0);
	ft_printf("FIELDS_SIZE: %d\n", (c->fields & FIELDS_SIZE) > 0);
	ft_printf("FIELDS_TIME: %d\n", (c->fields & FIELDS_TIME) > 0);
	ft_printf("FIELDS_FILENAME: %d\n", (c->fields & FIELDS_FILENAME) > 0);
	//ft_printf("TIME_TYPE\n");
	ft_printf("TT_CREATION_TIME: %d\n", (c->time_type & TT_CREATION_TIME) > 0);
	ft_printf("TT_ACCESS_TIME: %d\n", (c->time_type & TT_ACCESS_TIME) > 0);
	//ft_printf("FILES\n");
	ft_printf("FILES_REGULAR: %d\n", (c->files & FILES_REGULAR) > 0);
	ft_printf("FILES_HIDDEN: %d\n", (c->files & FILES_HIDDEN) > 0);
	ft_printf("FILES_SPECIAL: %d\n", (c->files & FILES_SPECIAL) > 0);
	//ft_printf("LIST_TYPE\n");
	ft_printf("LIST_TYPE_LIST: %d\n", (c->files & LIST_TYPE_LIST) > 0);
	ft_printf("LIST_TYPE_ROWS: %d\n", (c->files & LIST_TYPE_ROWS) > 0);
}
