/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:01:22 by pleander          #+#    #+#             */
/*   Updated: 2025/03/21 10:59:49 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "memlist.h"
#include "ft_ls.h"

static int	read_flag(char f, t_config *config)
{
	if (f == ' ')
		return (0);
	if (!ft_strchr(FLAGS, f))
		error_exit("Unsuppoted flag"); //TODO: better message
	if (f == 'a')
	{
		config->files |= FILES_HIDDEN;
		config->files |= FILES_SPECIAL;
	}
	return (1);
}

int	count_dirs(char **argv)
{
	int c;

	c = 0;
	while (*argv)
	{
		if (**argv != '-')
			c++;
		argv++;
	}
	if (c == 0)
		c = 1;
	return (c);
}

void	parse_args(int argc, char **argv, t_config *config, char **dirs)
{
	int		n;

	if (argc <= 1)
		return ;
	argv++;
	if (!dirs)
		error_exit("reserve");
	n = 0;
	while (argv && *argv)
	{
		if (**argv == '-')
		{
			(*argv)++;
			while(**argv)
			{
				read_flag(**argv, config);
				(*argv)++;
			}
		}
		else
			dirs[n] = *argv;
		argv++;
	}
}
