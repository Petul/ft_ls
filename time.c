/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:43:01 by pleander          #+#    #+#             */
/*   Updated: 2025/04/02 21:05:29 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft.h"
#include "memlist.h"
#include "ft_ls.h"

void get_mod_time(t_fields *fields, time_t *time)
{
	char *t;
	char *cur;
	char *min;
	char *mon;
	char *hm;

	t = ctime(time);
	cur = ft_strchr(t, ' ');
	// Todo: finish parse time from ctime string
}
