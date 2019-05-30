/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:48:50 by omaltsev          #+#    #+#             */
/*   Updated: 2018/12/22 17:24:30 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		square_size(int num)
{
	int	side;

	side = 1;
	num *= 4;
	while ((side * side) < num)
		side++;
	return (side);
}

void	make_square2(t_matrix *cor, t_matrix *row, int letter, char *square)
{
	int	i;
	int tmp;

	while (cor != row)
	{
		i = 0;
		tmp = 0;
		while (square[i])
		{
			if (square[i] == '\n')
			{
				i++;
				tmp++;
			}
			if (i == cor->x + tmp)
				square[i] = letter;
			i++;
		}
		cor = cor->right;
	}
}

void	make_square(t_stack *stack, int side, int num)
{
	char		*square;
	int			letter;
	t_matrix	*cor;
	t_stack		*temp;

	letter = 64 + num;
	square = empty_square(side);
	temp = stack;
	while (num > 0)
	{
		cor = temp->matrix;
		cor = cor->right;
		make_square2(cor, temp->matrix, letter, square);
		letter--;
		temp = temp->next;
		num--;
	}
	ft_putstr(square);
	free(square);
}
