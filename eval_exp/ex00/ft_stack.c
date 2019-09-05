/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvincent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:20:00 by tvincent          #+#    #+#             */
/*   Updated: 2019/08/18 16:53:10 by tvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		ft_list_push_int(t_ilist **begin_list, int data)
{
	t_ilist	*tmp;

	if (*begin_list)
	{
		tmp = ft_create_int(data);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_create_int(data);
}

int			ft_pop_int(t_ilist **begin_list)
{
	t_ilist	*tmp;
	int		data;

	if (*begin_list == NULL)
		return (0);
	tmp = *begin_list;
	*begin_list = (*begin_list)->next;
	data = tmp->data;
	free(tmp);
	return (data);
}

t_clist		*ft_create_char(char data)
{
	t_clist	*list;

	if (!(list = (t_clist*)malloc(sizeof(t_clist))))
		return (0);
	list->data = data;
	list->next = NULL;
	return (list);
}

void		ft_list_push_char(t_clist **begin_list, char data)
{
	t_clist	*tmp;

	if (*begin_list)
	{
		tmp = ft_create_char(data);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_create_char(data);
}

char		ft_pop_char(t_clist **begin_list)
{
	t_clist	*tmp;
	char	data;

	if (*begin_list == NULL)
		return (0);
	tmp = *begin_list;
	*begin_list = (*begin_list)->next;
	data = tmp->data;
	free(tmp);
	return (data);
}
