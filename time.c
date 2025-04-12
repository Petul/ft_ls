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
#include "ft_printf.h"
#include "libft.h"
#include "memlist.h"
#include "ft_ls.h"

/**
 * @brief Returns the n-th column (starting from 0), separated by space
 *
 * @param str: the string to search
 * @param c column index
 * @return 
 */
static char *get_column(char *str, int c)
{
	int i;
	int col;
	//char *prev;

	col = 0;
	i = 0;
	while (str[i])
	{
		if (i > 0 && str[i] != ' ' && str[i - 1] == ' ')
		{
			if (++col >= c)
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

static char *get_month(char *t)
{
	char *month;

	month = ft_substr(t, 4, 3);
	if (!month)
		error_exit("ft_substr");
	memlist_add(month);
	return (month);
}

static char *get_day(char *t)
{
	char	*day;
	int		len;

	day = get_column(t, 2);
	len = ft_strchr(day, ' ') - day;
	day = ft_strndup(day, len);
	if (!day)
		error_exit("ft_substr");
	memlist_add(day);
	return (day);
}

void get_mod_time(t_fields *fields, time_t *time)
{
	char	*t;
	int		len;
	char	*month;
	char	*day;

	t = ctime(time);
	//fields->time = t;
	month = get_month(t);
	day	= get_day(t);
	len = ft_snprintf(NULL, 0, "%s %s", month, day);
	if (len < 0)
		error_exit("ft_snprintf");
	fields->time = reserve(len + 1);
	if (!fields->time)
		error_exit("reserve");
	if (ft_snprintf(fields->time, len + 1, "%s %s", month, day) < 0)
		error_exit("ft_snprintf");
}
