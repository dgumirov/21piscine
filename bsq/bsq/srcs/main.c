/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:38:01 by ialleen           #+#    #+#             */
/*   Updated: 2019/08/20 13:49:11 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <time.h>
int			main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	c;

	i = 1;
	if (argc == 1)
	{
		if (!(fd = open("resources/temp.txt",
			O_APPEND | O_RDWR | O_CREAT | O_TRUNC)))
			return (list_error());
		while (read(0, &c, 1))
			write(fd, &c, 1);
		close(fd);
		work_with_file("resources/temp.txt");
	}
	while (i < argc)
		work_with_file(argv[i++]);
	return (0);
}

int			work_with_file(char *file_name)
{
	int		length;
	int		fd;
	char	**mas;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (list_error());
	length = check_valid_file(fd);
	close(fd);
	if (length && (fd = open(file_name, O_RDONLY)) != -1)
	{
		mas = file_to_mas(fd, length);
		find_square(mas, length);
		print(mas, length);
	}
	close(fd);
	return (0);
}
