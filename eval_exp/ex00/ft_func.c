/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvincent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:29:05 by tvincent          #+#    #+#             */
/*   Updated: 2019/08/18 16:35:04 by tvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		is_oper(char c)
{
	if (c == '+' || c == '-')
		return (2);
	else if (c == '*' || c == '%' || c == '/')
		return (3);
	else if (c == '!')
		return (4);
	else if (c == '(')
		return (1);
	else
		return (0);
}

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int	final;
	int	i;

	i = 0;
	final = 0;
	while (str[i] != '\0' && (!(is_oper(str[i]))))
	{
		if (str[i] >= '0' && str[i] <= '9')
			final = final * 10 + (str[i] - '0');
		i++;
	}
	return (final);
}

int		dig(char *str)
{
	char	*s;
	int		j;

	j = 0;
	s = (char *)(malloc(sizeof(char) * 12));
	while ((is_num(*str)) && (*str))
	{
		s[j] = *str;
		str++;
		j++;
	}
	s[j] = '\0';
	j = ft_atoi(s);
	free(s);
	return (j);
}

int		calc(char c, int a, int b)
{
	if (c == '+')
		return (b + a);
	else if (c == '-')
		return (b - a);
	else if (c == '*')
		return (b * a);
	else if (c == '/')
		return (b / a);
	else if (c == '%')
		return (b % a);
	else
		return (0);
}
