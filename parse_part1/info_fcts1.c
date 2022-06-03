/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_fcts1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:42:07 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/03 12:16:13 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

int	is_ceiling_floor(char *string)
{
	int	i;

	i = 0;
	skip_spaces(string, &i);
	if (string[i] == 'C' || string[i] == 'F')
		return (1);
	return (0);
}

void	give_rgb(char *string, t_info *infos)
{
	int		i;
	char	c;

	i = 0;
	skip_spaces(string, &i);
	c = string[i];
	norme1(string, &i);
	if (c == 'F')
	{
		infos->floor_color = malloc(sizeof(int) * 3);
		if (!(infos->floor_color))
			m_fail();
		infos->floor_color[0] = m_atoi(string, &i);
		infos->floor_color[1] = m_atoi(string, &i);
		infos->floor_color[2] = m_atoi(string, &i);
	}
	else if (c == 'C')
	{
		infos->ceiling_color = malloc(sizeof(int) * 3);
		if (!(infos->floor_color))
			m_fail();
		infos->ceiling_color[0] = m_atoi(string, &i);
		infos->ceiling_color[1] = m_atoi(string, &i);
		infos->ceiling_color[2] = m_atoi(string, &i);
	}
}

void	give_texture_file(t_info *info, char *string)
{
	int		i;
	char	c;

	i = 0;
	skip_spaces(string, &i);
	c = string[i];
	i += 2;
	skip_spaces(string, &i);
	i += 2;
	if (c == 'E')
		info->east_texture = remove_nl(ft_strdup(&string[i]));
	else if (c == 'W')
		info->west_texture = remove_nl(ft_strdup(&string[i]));
	else if (c == 'S')
		info->south_texture = remove_nl(ft_strdup(&string[i]));
	else if (c == 'N')
		info->north_texture = remove_nl(ft_strdup(&string[i]));
}

int	is_texture(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == 'S' || string[i] == 'N'
			|| string[i] == 'E' || string[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

void	give_infos(t_info *infos, char **file)
{
	int	i;

	i = -1;
	while (file[++i] != NULL)
	{
		if (file[i][0] != '\n' && is_ceiling_floor(file[i]))
			give_rgb(file[i], infos);
		else if (file[i][0] != '\n' && is_texture(file[i]))
			give_texture_file(infos, file[i]);
	}
	i = -1;
	while (file[++i] != NULL)
		free(file[i]);
	free(file);
}
