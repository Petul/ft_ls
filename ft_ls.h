/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:24:16 by pleander          #+#    #+#             */
/*   Updated: 2025/05/08 21:28:01 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/stat.h>
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
#define FIELDS_BLOCKS		(1 << 7)

#define TT_CREATION_TIME	(1 << 0)
#define TT_ACCESS_TIME		(1 << 1)

#define FILES_REGULAR		(1 << 0)
#define FILES_HIDDEN		(1 << 1)
#define FILES_SPECIAL		(1 << 2)

#define LIST_TYPE_LIST		(1 << 0)
#define LIST_TYPE_ROWS		(1 << 1)

#define OTHER_TOTAL_BLOCKS	(1 << 0)
#define OTHER_RECURSIVE		(1 << 1)

#define FLAGS "alsR"

typedef struct s_config
{
	uint8_t fields;
	uint8_t time_type;
	uint8_t files;
	uint8_t list_type;
	uint8_t sort_by;
	uint8_t other;

}	t_config;

typedef struct	s_fields
{
	char	*mode;
	char	*hard_links;
	char	*owner;
	char	*group;
	char	*size;
	int		blocks_int;
	char	*blocks;
	char	*month;
	char	*day;
	char	*time;
	char	*year;
	char	*filename;
}	t_fields;

typedef struct s_totals {
	int	total_blocks;
	int fw_blocks;
	int fw_mode;
	int	fw_hard_links;
	int	fw_owner;
	int	fw_group;
	int	fw_size;
	int	fw_month;
	int	fw_day;
	int	fw_time;
	int	fw_year;
	int	fw_filename;
}	t_totals;

typedef struct dirent t_dirent;

int		ft_ls(char *path, t_config *config);
void	apply_default_config(t_config *c);
void	print_config(t_config *c);
void	error_exit(char *msg);
void	sort_files(t_list **files, t_config *config);
void	print_list(t_list **dirc, t_config *config);
void	parse_args(int argc, char **argv, t_config *config, t_list **dirs);
int		count_dirs(char **argv);
void	get_mode(t_fields *fields, struct stat *statbuf);
void	get_hard_link_count(t_fields *fields, struct stat *statbuf);
void	get_uid(t_fields *fields, int uid);
void	get_gid(t_fields *fields, int uid);
void	get_size(t_fields *fields, int size);
void	get_mod_time(t_fields *fields, time_t *time);
char	*get_column(char *str, int c);
void	calc_totals(t_list *dirc, t_totals *totals);
void	get_blocks(t_fields *fields, int blocks);
void	add_dirs_recursively(t_list *dirs, t_config *config);

#endif
