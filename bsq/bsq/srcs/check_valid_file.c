/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:36:00 by ialleen           #+#    #+#             */
/*   Updated: 2019/08/20 10:55:50 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int			length_line(int fd, char *leg, int count_lines, int length)
{
	int		r;
	char	c;
	int		t;
	int		flag_box;

	flag_box = 0;
	r = read(fd, &c, 1);
	while (r && (count_lines-- + 2))
	{
		r = (c == '\n') ? read(fd, &c, 1) : r;
		t = 0;
		while (c != '\n' && c && r && ++t)
		{
			if (c != leg[0] && c != leg[1])
				return (list_error());
			flag_box = (c == leg[0]) ? 1 : flag_box;
			r = read(fd, &c, 1);
		}
		length = (length == 0) ? t : length;
		if (count_lines < 0)
			return (list_error());
		if (t != length && r)
			return (list_error());
	}
	return (count_lines || flag_box == 0 ? list_error() : length);
}

int			check_valid_file(int fd)
{
	long	count_lines;
	int		r;
	char	c;
	char	leg[3];

	leg[0] = 0;
	leg[1] = 0;
	leg[2] = 0;
	count_lines = 0;
	while ((r = read(fd, &c, 1) != -1) && (c != '\n') && c)
	{
		if (c >= '0' && c <= '9' && leg[0] == 0)
			count_lines = count_lines * 10 + (c - '0');
		else if (count_lines != 0 && c > 32 && c < 127 && leg[0] == 0)
			leg[0] = c;
		else if (count_lines != 0 && c > 32 && c < 127 && leg[1] == 0)
			leg[1] = c;
		else if (count_lines != 0 && c > 32 && c < 127 && leg[2] == 0)
			leg[2] = c;
		else
			return (list_error());
	}
	if (leg[0] == leg[1] || leg[1] == leg[2] || leg[0] == leg[2] || leg[2] == 0)
		return (list_error());
	return (length_line(fd, leg, count_lines + 1, 0));
}
