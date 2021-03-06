/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:34:11 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/03 12:13:19 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

char	**push_st(char **double_p, char *to_put_in)
{
	char	**ret;
	int		i;

	if (double_p == NULL)
		return (norme2(to_put_in));
	i = 0;
	while (double_p[i] != NULL)
		i++;
	ret = malloc(sizeof(char *) * (i + 2));
	if (!ret)
		m_fail();
	i = 0;
	while (double_p[i] != NULL)
	{
		ret[i] = ft_strdup(double_p[i]);
		free(double_p[i]);
		i++;
	}
	ret[i] = ft_strdup(to_put_in);
	ret[i + 1] = NULL;
	free(double_p);
	return (ret);
}

char	**file_to_2darr(char *file)
{
	char	*tmp_string;
	char	**return_va;
	int		fd;

	fd = open(file, O_RDONLY);
	return_va = NULL;
	tmp_string = NULL;
	tmp_string = get_next_line(fd);
	while (tmp_string != NULL)
	{
		return_va = push_st(return_va, tmp_string);
		free(tmp_string);
		tmp_string = get_next_line(fd);
	}
	return (return_va);
}
