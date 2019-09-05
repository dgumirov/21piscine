/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvincent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:30:07 by tvincent          #+#    #+#             */
/*   Updated: 2019/08/11 22:41:18 by tvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sud.h"

int		full_board(int board[9][9])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 9)
	{
		while (i < 9)
		{
			if (save(board, j, i, board[j][i]) == 0)
				return (ft_error());
			i++;
		}
		i++;
		j++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
