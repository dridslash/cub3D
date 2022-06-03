/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:58:23 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/03 16:52:42 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSE_H
# define FILE_PARSE_H

# include "gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>

typedef struct map_info
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		*floor_color;
	int		*ceiling_color;
}t_info;

typedef struct map_check
{
	int	north_tex;
	int	south_tex;
	int	east_tex;
	int	west_tex;
	int	floor_color;
	int	ceiling_color;
}t_mapCheck;

void	norme5(t_mapCheck *info_check, char *s, char **file);
void	norme4(int *i, char *string, char **s);
void	norme1(char *string, int *i);
void	m_fail(void);
void	give_texture_file(t_info *infos, char *string);
void	give_infos(t_info *infos, char **file);
void	give_rgb(char *string, t_info *infos);
void	exit_msg(char **s);
void	check_struct(t_mapCheck *info, char **s);
void	init_info_check(t_mapCheck *info);
void	skip_spaces(char *string, int *i);
void	check_args(int argc);
void	check_file_name(char *file);
void	check_file_permissions(char *file);
char	**check_infos_in(char **file);
char	**check_file_args(int argc, char **argv);
char	**file_to_2darr(char *file);
char	**push_st(char **double_p, char *to_put_in);
char	**duplicate_double_p(char **file, int i);
char	*remove_nl(char *s);
char	**norme2(char *to_put_in);
int		ft_lenp(char **p);
int		check_range(char *string);
int		check_ceil_floor(char *string, char **s);
int		ft_strncmp(char *s1, char *s2, int n);
int		is_good_num(char *string, int *i, int option, char **s);
int		texture_check(char *string, char **s);
int		which_texture(char *string);
int		is_1(t_mapCheck *info);
int		is_ceiling_floor(char *string);
int		m_atoi(char *string, int *i);
int		is_texture(char *string);
int		norme3(char *string, int i);
int		give_value1(char *string, int *i);
int		give_value2(char *string, int *i, char **s);
int 	ff_strlen(char *s);
char  *observer_checker_map(char **map);
#endif
