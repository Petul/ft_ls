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

#include "libft.h"
#include "memlist.h"
#include "ft_printf.h"
#include "ft_ls.h"

static void	list_dirs(t_list *dirs, t_config *config);

int	main(int argc, char **argv)
{
	t_config config;
	t_list	*dirs;

	dirs = NULL;
	apply_default_config(&config);
	parse_args(argc, argv, &config, &dirs);
	int size = ft_lstsize(dirs);
	if (size == 0)
	{
		t_list *new = ft_lstnew(".");
		memlist_add(new);
		ft_lstadd_back(&dirs, new);
	}
	list_dirs(dirs, &config);
	memlist_release_all();
	return (0);
}

static void	list_dirs(t_list *dirs, t_config *config)
{
	int n;
	int	i;

	i = 0;
	n = ft_lstsize(dirs);
	while(dirs)
	{
		if (n > 1)
			ft_printf("%s:\n", (char *)dirs->content);
		ft_ls(dirs->content, config);
		if (i != n - 1)
			ft_printf("\n");
		i++;
		dirs = dirs->next;
	}
}
