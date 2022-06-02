/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error_fcts1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:00:55 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 21:49:49 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

void	check_args(int argc)
{
	if (argc == 1)
		printf("Error\nThere must be 2 arguments.\n");
	else if (argc > 2)
		printf("Error\nToo many arguments found.\n");
	if (argc == 1 || argc > 2)
		exit(EXIT_FAILURE);
}

void	check_file_name(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[0] == '.')
	{
		printf("Error\nHidden file detected.\n");
		exit(EXIT_FAILURE);
	}
	while (i >= 0)
	{
		if (file[i] == '.')
		{
			if (ft_strncmp(&file[i], ".cub", 4) == 0 && file[i + 4] == '\0')
				return ;
		}
		i--;
	}
	printf("Error\n");
	printf("Map not ending with '.cub' extension.\n");
	exit(EXIT_FAILURE);
}

void	check_file_permissions(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		perror(file);
		exit(EXIT_FAILURE);
	}
}

char	**check_file_args(int argc, char **argv)
{
	char	**ptr;

	ptr = NULL;
	check_args(argc);
	check_file_name(argv[1]);
	check_file_permissions(argv[1]);
	ptr = file_to_2darr(argv[1]);
	if (ptr == NULL || ft_lenp(ptr) < 9)
		exit_msg(ptr);
	return (ptr);
}
