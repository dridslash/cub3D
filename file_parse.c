/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:34:11 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/17 18:17:51 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

char **push_st(char **double_p, char *to_put_in)
{
    char    **ret;
    int     i;

    if (double_p == NULL)
    {
        ret = malloc(sizeof(char *) * 2);
        ret[0] = ft_strdup(to_put_in);
        ret[1] = NULL;
        return (ret);
    }
    i = 0;
    while (double_p[i] != NULL)
        i++;
    ret = malloc(sizeof(char *) * (i + 1));
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

char **file_to_2darr(char *file)
{
    char    *tmp_string;
    char    **return_va;
    int     fd;

    fd = open(file, O_RDONLY);
    return_va = NULL;
    tmp_string = NULL;
    tmp_string = get_next_line(fd);
    while (tmp_string != NULL)
    {
    printf("Here\n");
        return_va = push_st(return_va, tmp_string);
        tmp_string = get_next_line(fd);
    }
    return (return_va);
}

int main(int argc, char **argv)
{
    char **double_p;
    argc = 1;
    double_p = file_to_2darr(argv[1]);

    return (0);
}