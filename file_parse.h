/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:58:23 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/17 17:15:42 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSE_H
# define FILE_PARSE_H

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>

//File handling
void    check_args(int argc);
void    check_file_name(char *file);
void    check_file_permissions(char *file);

#endif