/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_mas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:37:41 by ialleen           #+#    #+#             */
/*   Updated: 2019/08/20 13:48:20 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void		mas_leg(int fd)
{
	int		r;
	char	c;

	g_leg[0] = 0;
	g_leg[1] = 0;
	g_leg[2] = 0;
	g_leg[3] = 0;
	while ((r = read(fd, &c, 1) != -1) && c != '\n' && c)
	{
		if (c >= '0' && c <= '9' && g_leg[1] == 0)
			g_leg[0] = g_leg[0] * 10 + (c - '0');
		else if (g_leg[1] == 0)
			g_leg[1] = c;
		else if (g_leg[2] == 0)
			g_leg[2] = c;
		else if (g_leg[3] == 0)
			g_leg[3] = c;
	}
}

char		**file_to_mas(int fd, int length)
{
	int		r;
	char	**mas;
	int		i;
	char	c;
	int		j;

	i = 0;
	mas_leg(fd);
	r = read(fd, &c, 1);
	if (!(mas = (char **)malloc(sizeof(char *) * g_leg[0])))
		return (NULL);
	while (i < g_leg[0])
	{
		r = (c == '\n') ? read(fd, &c, 1) : r;
		if (!(mas[i] = (char *)malloc(sizeof(char) * length)))
			return (NULL);
		j = 0;
		while (j < length)
		{
			mas[i][j++] = c;
			r = read(fd, &c, 1);
		}
		i++;
	}
	return (mas);
}

void		print(char **mas, int length)
{
	int		i;
	char	c;
	int		j;

	c = '\n';
	i = 0;
	while (i < g_leg[0])
	{
		j = 0;
		while (j < length)
		{
			if ((i >= g_leg[4] && i < (g_leg[4] + g_leg[6])) &&
				(j >= g_leg[5] && j < (g_leg[5] + g_leg[6])))
				write(1, &g_leg[3], 1);
			else
				write(1, &mas[i][j], 1);
			ft_putstr(1, SPACE);
			j++;
		}
		free(mas[i]);
		write(1, &c, 1);
		i++;
	}
	free(mas);
}
