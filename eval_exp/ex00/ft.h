/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvincent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:20:39 by tvincent          #+#    #+#             */
/*   Updated: 2019/08/18 16:48:25 by tvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_ilist
{
	struct s_ilist	*next;
	int				data;
}					t_ilist;

typedef struct		s_clist
{
	struct s_clist	*next;
	char			data;
}					t_clist;

t_ilist				*ft_create_int(int data);
t_clist				*ft_create_char(char data);
void				ft_list_push_int(t_ilist **begin_list, int data);
void				ft_list_push_char(t_clist **begin_list, char data);
int					ft_pop_int(t_ilist **begin_list);
char				ft_pop_char(t_clist **begin_list);
void				ft_putnbr(int nb);
void				ft_putnbr(int nb);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
int					is_oper(char c);
int					is_num(char c);
int					ft_atoi(char *str);
int					dig(char *str);
int					calc(char c, int a, int b);

#endif
