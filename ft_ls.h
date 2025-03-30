/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:24:16 by pleander          #+#    #+#             */
/*   Updated: 2025/03/27 21:16:14 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

#ifndef FT_LS_H
# define FT_LS_H

#define FIELDS_MODE			(1 << 0)
#define FIELDS_COUNT		(1 << 1)
#define FIELDS_OWNER		(1 << 2)
#define FIELDS_GROUP		(1 << 3)
#define FIELDS_SIZE			(1 << 4)
#define FIELDS_TIME			(1 << 5)
#define FIELDS_FILENAME		(1 << 6)

#define TT_CREATION_TIME	(1 << 0)
#define TT_ACCESS_TIME		(1 << 1)

#define FILES_REGULAR		(1 << 0)
#define FILES_HIDDEN		(1 << 1)
#define FILES_SPECIAL		(1 << 2)

#define LIST_TYPE_LIST		(1 << 0)
#define LIST_TYPE_ROWS		(1 << 1)

#define FLAGS "al"

typedef struct s_config
{
	uint8_t fields;
	uint8_t time_type;
	uint8_t files;
	uint8_t list_type;
	uint8_t sort_by;

}	t_config;

typedef struct	s_fields
{
	char	*mode;
	char	*hard_links;
	char	*owner;
	char	*group;
	char	*size;
	char	*time;
	char	*filename;
}	t_fields;

typedef struct dirent t_dirent;

int		ft_ls(char *path, t_config *config);
void	apply_default_config(t_config *c);
void	print_config(t_config *c);
void	error_exit(char *msg);
void	sort_files(t_list **files, t_config *config);
void	print_list(char *dirpath, t_list **dirc, t_config *config);
void	parse_args(int argc, char **argv, t_config *config, t_list **dirs);
int		count_dirs(char **argv);
void	get_mode(t_fields *fields, char *fpath);

#endif
