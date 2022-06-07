/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:20:01 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/03 11:03:52 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

void	exit_msg(char **s)
{
	int	i;

	i = -1;
	if (s != NULL)
	{
		while (s[++i] != NULL)
			free(s[i]);
		free(s);
	}
	printf("Error\nFile not ready to parse.\n");
	exit(EXIT_FAILURE);
}

int	ft_lenp(char **p)
{
	int	len;

	len = 0;
	while (p[len] != NULL)
		len++;
	return (len);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	c;

	c = 0;
	while ((s1[c] != '\0' || s2[c] != '\0') && c < n)
	{
		if (s1[c] != s2[c])
			return (((unsigned char)s1[c] - (unsigned char)s2[c]));
		c++;
	}
	return (0);
}

int	is_1(t_mapCheck *info)
{
	if (info->ceiling_color == 1 && info->east_tex == 1
		&& info->floor_color == 1 && info->north_tex
		&& info->south_tex == 1 && info->west_tex == 1)
		return (1);
	return (0);
}

char	**duplicate_double_p(char **file, int i)
{
	char	**ret;
	int		j;

	j = 0;
	while (file[i][0] == '\n')
		i++;
	ret = malloc(sizeof(char *) * (ft_lenp(&file[i]) + 1));
	if (!ret)
	{
		printf("Malloc Fail.\n");
		exit(EXIT_FAILURE);
	}
	while (file[i] != NULL)
	{
		ret[j] = ft_strdup(file[i]);
		j++;
		i++;
	}
	ret[j] = NULL;
	return (ret);
}
