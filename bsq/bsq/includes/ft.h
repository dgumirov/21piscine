/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:32:41 by ialleen           #+#    #+#             */
/*   Updated: 2019/08/20 14:10:14 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define SPACE ""
# define M(x, y) (((x) < (y)) ? (x) : (y))

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>

int		check_valid_file(int fd);
int		ft_putstr(int s, char *str);
int		list_error(void);
int		length_line(int fd, char *leg, int count_lines, int length);
void	mas_leg(int fd);
char	**file_to_mas(int fd, int length);
void	print(char **mas, int length);
int		work_with_file(char *file_name);
int		g_leg[7];
int		dupl(char c);
void	find_square(char **mat, int length);

#endif
