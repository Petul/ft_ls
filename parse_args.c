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
	if (f == 'l')
	{
		config->fields = 255; // Enable all fields
		config->fields ^= FIELDS_BLOCKS; // Disable block view by default
		config->other |= OTHER_TOTAL_BLOCKS;
	}
	if (f == 's')
	{
		config->fields |= FIELDS_BLOCKS;
		config->other |= OTHER_TOTAL_BLOCKS;
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

static void	add_to_list(t_list **dirs, char *arg)
{
	t_list	*new;

	new = ft_lstnew(arg);
	if (!new)
		error_exit("ft_lstnew");
	if (!memlist_add(new))
		error_exit("memlist_add");
	ft_lstadd_back(dirs, new);
}

void	parse_args(int argc, char **argv, t_config *config, t_list **dirs)
{
	if (argc <= 1)
		return ;
	argv++;
	if (!dirs)
		error_exit("reserve");
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
			add_to_list(dirs, *argv);
		argv++;
	}
}
