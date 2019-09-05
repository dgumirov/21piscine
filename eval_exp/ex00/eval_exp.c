/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_exp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvincent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:59:44 by tvincent          #+#    #+#             */
/*   Updated: 2019/08/20 16:39:34 by tvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		g_flag = 0;
t_ilist	*g_nu = NULL;
t_clist	*g_op = NULL;

int		cmp_op(char cstack, char c)
{
	int	a;
	int	b;

	if (cstack == '+' || cstack == '-')
		a = 1;
	else if (cstack == '*' || cstack == '/' || cstack == '%')
		a = 2;
	else
		a = 0;
	if (c == '+' || c == '-')
		b = 1;
	else if (c == '*' || c == '/' || c == '%')
		b = 2;
	else
		b = 3;
	return (a >= b ? 1 : 0);
}

char	*if_parath(char *str)
{
	if (*str == ')')
	{
		while ((g_op->data != '(') && (g_op))
			ft_list_push_int(&g_nu, calc(ft_pop_char(&g_op),
						ft_pop_int(&g_nu), ft_pop_int(&g_nu)));
		ft_pop_char(&g_op);
		if (*str)
			str++;
	g_flag = 1;
	}
	else if (*str == '(')
	{
		ft_list_push_char(&g_op, *str);
		str++;
//	g_flag = 0;
	}
	return (str);
}

char	*if_oper(char *str)
{
	if (g_flag)
	{
		if (!(g_op == NULL) && (!(cmp_op(g_op->data, *str))))
			ft_list_push_char(&g_op, *str);
		else if (g_op == NULL)
			ft_list_push_char(&g_op, *str);
		else if (!(g_op == NULL) && (cmp_op(g_op->data, *str)))
		{
			ft_list_push_int(&g_nu, calc(ft_pop_char(&g_op),
						ft_pop_int(&g_nu), ft_pop_int(&g_nu)));
			ft_list_push_char(&g_op, *str);
		}
		str++;
		g_flag = 0;
	}
	else
	{
		while (!(is_num(*str)) && (*str))
			str++;
		ft_list_push_int(&g_nu, (dig(str) * -1));
		while ((is_num(*str)) && (*str))
			str++;
		g_flag = 1;
	}
	return (str);
}

int		eval_expr(char *str)
{
	int		res;

	while (*str != '\0')
	{
		if (*str == ')' || *str == '(')
			str = if_parath(str);
		else if (is_num(*str) && (*str))
		{
			ft_list_push_int(&g_nu, (dig(str)));
			while ((is_num(*str)) && (*str))
				str++;
			g_flag = 1;
		}
		else if (is_oper(*str) && (*str))
			str = if_oper(str);
		else
			str++;
	}
	while (g_op)
		ft_list_push_int(&g_nu, calc(ft_pop_char(&g_op),
					ft_pop_int(&g_nu), ft_pop_int(&g_nu)));
	res = g_nu->data;
	return (res);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
