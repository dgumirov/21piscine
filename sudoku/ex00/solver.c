/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvincent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:24:30 by tvincent          #+#    #+#             */
/*   Updated: 2019/08/11 22:42:31 by tvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sud.h"

int g_a;

void	printer(int board[9][9])
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 9)
	{
		while (x < 9)
		{
			ft_putchar(board[y][x] + '0');
			if (x < 8)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
	g_a = 1;
}

int		save(int board[9][9], int x, int y, int val)
{
	int i;
	int j;
	int xn;

	i = -1;
	j = -1;
	while (++i < 9)
	{
		if ((board[y][i] == val && i != x) || (board[i][x] == val && i != y))
			return (0);
	}
	i = -1;
	xn = x - x % 3;
	while (++i < 3)
	{
		while (++j < 3)
		{
			if ((board[y - y % 3 + i][xn + j] == val) &&
				((y - y % 3 + i) != y && (xn + j != x)))
				return (0);
		}
		j = -1;
	}
	return (1);
}

void	solver(int board[9][9], int x, int y, int val)
{
	if (!board[y][x])
	{
		while (++val < 10)
		{
			if (save(board, x, y, val))
			{
				board[y][x] = val;
				if (y == 8 && x == 8)
					printer(board);
				if (x < 8)
					solver(board, x + 1, y, 0);
				else if (y < 8)
					solver(board, 0, y + 1, 0);
				board[y][x] = 0;
			}
		}
	}
	else if (x < 8)
		solver(board, x + 1, y, 0);
	else if (y < 8)
		solver(board, 0, y + 1, 0);
	else if (x == 8 && y == 8)
		printer(board);
}

int		chr_int(int board[9][9], char **argv, int flag)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++j < 10)
	{
		while (++i < 9)
		{
			if (argv[j][i] >= '1' && argv[j][i] <= '9')
				board[j - 1][i] = (argv[j][i] - '0');
			else if (argv[j][i] == '.')
			{
				board[j - 1][i] = 0;
				flag = 0;
			}
			else
				return (ft_error());
		}
		i = -1;
	}
	if (flag)
		return (full_board(board));
	else
		return (1);
}

int		main(int argc, char **argv)
{
	int board[9][9];

	g_a = 0;
	if (argc != 10)
		return (ft_error());
	if (!(chr_int(board, argv, 1)))
		return (0);
	solver(board, 0, 0, 0);
	if (g_a == 0)
		ft_error();
	return (0);
}
