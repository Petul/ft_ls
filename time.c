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

/**
 * @brief Returns the n-th column (starting from 0), separated by space
 *
 * @param str: the string to search
 * @param c column index
 * @return 
 */
char *get_column(char *str, int c)
{
	int i;
	int col;

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
		error_exit("ft_strndup");
	memlist_add(day);
	return (day);
}

static char *get_time(char *t)
{
	char	*tim;

	tim = get_column(t, 3);
	tim = ft_strndup(tim, 5);
	if (!tim)
		error_exit("ft_strndup");
	memlist_add(tim);
	return (tim);
}

static char *get_year(char *t)
{
	char	*year;
	int		len;

	year = get_column(t, 4);
	len = ft_strchr(year, '\n') - year;
	year = ft_strndup(year, len);
	if (!year)
		error_exit("ft_strndup");
	memlist_add(year);
	return (year);
}

void get_mod_time(t_fields *fields, time_t *time)
{
	char	*t;

	t = ctime(time);
	fields->month = get_month(t);
	fields->day = get_day(t);
	fields->time = get_time(t);
	fields->year = get_year(t);
}
