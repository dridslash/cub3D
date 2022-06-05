/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:58:23 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/05 17:26:04 by mnaqqad          ###   ########.fr       */
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

//------------------PART_1_OF_PARSING_------------------------
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

//------------------PART_2_OF_PARSING_------------------------
int		ff_strlen(char *s);
void	observer_checker_map(char **map);
void	check_right_side(char **map);
void	check_left_side(char **map);
void	check_line_zero_validity(char **map, int line_ind);
void	check_body_lines_for_zero(char **map);
void	check_body_lines(char **map);
void	check_for_empty_line(char **map);
void	check_pillar_walls(char *holder_line);
void	piller_check(char *holder_line, int line_pos, char **map);
int		get_sp_count(char *holder_line);
void	observ_pillar_walls(char *holder_line, int line_pos, char **map);
int		count_line_for_map(char **map);
int		get_lenght_based_chr(char *map);
void	count_check_elements(char **map);
int		pure_space_empty_line(char **map);
void	check_first_last_line(char **map);
void	element_body_line_check(char **map);
void	check_up_down(char **map);
void	check_sides(char **map);
void	element_body_line_check(char **map);
void	element_body_line_check_helper(char **map, int x, int y);
int		count_line_for_map(char **map);
int		get_lenght_based_chr(char *map);
void	check_first_last_line_helper(char **map, int x, int y);
void	init_pure_spaces_func(int *x, int *y, int *pure_count_spaces);
void	check_line_zero_validity_helper(char **map,
			int hold_index, int y, int x);
void	count_north(char **map, int *count_elm_n, int y_s);
void	count_south(char **map, int *count_elm_s, int y_s);
void	count_west(char **map, int *count_elm_w, int y_s);
void	count_east(char **map, int *count_elm_e, int y_s);
void	check_north(int count_elm_n,
			int count_elm_s, int count_elm_e, int count_elm_w);
void	check_south(int count_elm_n,
			int count_elm_s, int count_elm_e, int count_elm_w);
void	check_west(int count_elm_n,
			int count_elm_s, int count_elm_e, int count_elm_w);
void	check_east(int count_elm_n,
			int count_elm_s, int count_elm_e, int count_elm_w);
#endif
