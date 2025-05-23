/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:36:43 by pleander          #+#    #+#             */
/*   Updated: 2025/03/20 15:27:51 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "memlist.h"

void	error_exit(char *msg)
{
	ft_dprintf(STDERR_FILENO, "Error: %s\n", msg);
	memlist_release_all();
	exit(1);
}
