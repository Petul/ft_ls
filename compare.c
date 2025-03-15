/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:55:33 by pleander          #+#    #+#             */
/*   Updated: 2025/03/15 21:06:08 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int lexcmp(const char *s1, const char *s2)
{
	size_t	i;
	int c1;
	int c2;

	i = 0;
	c1 = ft_toupper(s1[i]);
	c2 = ft_toupper(s2[i]);
	while (c1 == c2 && c1)
	{
		i++;
		c1 = ft_toupper(s1[i]);
		c2 = ft_toupper(s2[i]);
	}
	return ((unsigned char)c1 - (unsigned char)c2);
}
