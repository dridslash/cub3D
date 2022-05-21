/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:45:14 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/21 12:57:42 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# include <stdlib.h>

# include <limits.h>

# include <stdio.h>
#define BUFFER_SIZE 10000

int		check_nl(char *string);
int		ft_strlen(char *string);
char	*get_next_line(int fd);
char	*ft_strdup(char *string);
char	*ft_strjoin(char *s1, char *s2);
char	*read_file(int fd);
char	*get_before_nl(char *buffer, int option);
char	*join_and_free(char *ret_string, char *buffer);
void	get_after_nl(char *buff);
void	ft_zero(char *buff);

#endif
