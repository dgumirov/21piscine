/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvincent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 17:37:33 by tvincent          #+#    #+#             */
/*   Updated: 2019/08/11 22:37:59 by tvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUD_H
# define SUD_H

# include <unistd.h>

int		full_board(int board[9][9]);
void	printer(int board[9][9]);
void	ft_putchar(char c);
int		ft_error(void);
int		save(int board[9][9], int x, int y, int val);
void	solver(int board[9][9], int x, int y, int val);
int		chr_int(int board[9][9], char **argv, int flag);

#endif
