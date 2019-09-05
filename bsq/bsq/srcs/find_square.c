/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:26:32 by ialleen           #+#    #+#             */
/*   Updated: 2019/08/20 13:45:14 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		dupl(char c)
{
	if (c == g_leg[1])
		return (1);
	else
		return (0);
}

void	find_square(char **mat, int length)
{
	int	l[g_leg[0]][length];
	int	i;
	int	j;

	i = -1;
	j = -1;
	g_leg[6] = 0;
	while (++i < g_leg[0])
	{
		while (++j < length)
		{
			l[i][j] = dupl(mat[i][j]);
			if (i && j && mat[i][j] == g_leg[1])
				l[i][j] = M(M(l[i][j - 1], l[i - 1][j]), l[i - 1][j - 1]) + 1;
			if (g_leg[6] < l[i][j])
			{
				g_leg[6] = l[i][j];
				g_leg[4] = i - g_leg[6] + 1;
				g_leg[5] = j - g_leg[6] + 1;
			}
		}
		j = -1;
	}
}
