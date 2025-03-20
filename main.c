/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:37:58 by pleander          #+#    #+#             */
/*   Updated: 2025/03/20 16:07:53 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "memlist.h"

int	main(int argc, char **argv)
{
	t_config config;
	apply_default_config(&config);
	parse_flags(argc, argv, &config);
	//print_config(&config);
	ft_ls(".", &config, 0);
	memlist_release_all();
	return (0);
}
