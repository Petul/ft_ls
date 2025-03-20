/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:01:22 by pleander          #+#    #+#             */
/*   Updated: 2025/03/20 15:58:41 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

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

void	parse_flags(int argc, char **argv, t_config *config)
{
	int f;

	if (argc <= 1)
		return;
	argv++;
	f = 0;
	while (argv && *argv)
	{
		while(**argv)
		{
			if (**argv == '-')
				f = 1;
			else if (f)
			{
				if (!read_flag(**argv, config))
					f = 0;
			}
			(*argv)++;
		}
		argv++;
	}
	
}
