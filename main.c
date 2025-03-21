/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:37:58 by pleander          #+#    #+#             */
/*   Updated: 2025/03/21 10:40:07 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "memlist.h"

int	main(int argc, char **argv)
{
	t_config config;
	char **dirs;

	dirs = creserve(count_dirs(argv), sizeof(char *));
	if (!dirs)
		error_exit("creserve");
	apply_default_config(&config);
	parse_args(argc, argv, &config, dirs);
	//print_config(&config);
	if (!dirs[0])
		dirs[0] = ".";
	ft_ls(dirs[0], &config, 0);
	memlist_release_all();
	return (0);
}
