/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sasta_ver2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvincent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:29:36 by tvincent          #+#    #+#             */
/*   Updated: 2019/08/04 20:45:06 by tvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_shift(int size)
{
	if (size == 1)
	{
		return (0);
	}
	return (size / 2 + 1);
}

void	ft_drawer(int space_cnt, int first_star)
{
	int i;

	i = 0;
	while (i++ < space_cnt)
		ft_putchar(' ');
	i = 0;
	ft_putchar('/');
	while (i++ < first_star * 2 - 1)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void	ft_door(int space_cnt, int first_star, int door)
{
	int i;
	int j;

	i = 0;
	j = door;
	while (i++ < space_cnt)
		ft_putchar(' ');
	i = 0;
	ft_putchar('/');
	while (i++ < first_star - 1)
		ft_putchar('*');
	while (j-- != 0)
		if (j == 1 && space_cnt == door / 2 && door >= 5)
			ft_putchar('$');
		else
			ft_putchar('|');
	i = 0;
	while (i++ < first_star - 1)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void	ft_builder(int space_cnt, int size, int door_size)
{
	int cur_floor;
	int cur_line;
	int stars;
	int i;

	stars = 0;
	cur_line = 1;
	cur_floor = 0;
	i = 0;
	while (cur_floor++ < size)
	{
		cur_line = 1;
		stars = stars + ft_shift(cur_floor);
		while (cur_line++ <= cur_floor + 2)
		{
			stars++;
			if (cur_floor == size && cur_line > size + 3 - door_size)
				ft_door(space_cnt - i, stars - door_size / 2, door_size);
			else
				ft_drawer(space_cnt - i, stars);
			i++;
		}
		space_cnt = space_cnt - ft_shift(cur_floor + 1);
	}
}

void	sastantua(int size)
{
	int space_cnt;
	int door_size;
	int i;

	i = 0;
	space_cnt = 0;
	while (i < size)
	{
		space_cnt = space_cnt + (size - i) + 2 + ft_shift(size - i);
		i++;
	}
	door_size = size - 1;
	if (size % 2 != 0)
		door_size = door_size + 1;
	ft_builder(space_cnt - 1, size, door_size);
}
