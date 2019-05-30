/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:05:14 by yhliboch          #+#    #+#             */
/*   Updated: 2018/12/22 17:25:13 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack *stack1;

	stack1 = *stack;
	while (stack1 != NULL)
	{
		temp = stack1->next;
		free(stack1);
		stack1 = temp;
	}
	*stack = NULL;
}

int		*cor(char *str)
{
	int	*rescor;
	int	i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	rescor = (int *)malloc(sizeof(int) * 4 + 1);
	while (str[i])
	{
		if (str[i] == '#')
		{
			rescor[j] = count;
			j++;
		}
		i++;
		count++;
	}
	rescor[j] = '\0';
	return (rescor);
}

char	*empty_square(int side)
{
	int		i;
	int		s;
	char	*str;

	i = 0;
	s = side * side + side;
	str = ft_strnew(s);
	while (i < s)
	{
		if ((i % (side + 1)) == side)
			str[i] = '\n';
		else
			str[i] = '.';
		i++;
	}
	return (str);
}

void	hesh(char **new, char *str, int count)
{
	int		i;
	int		temp;
	char	*new2;

	new2 = *new;
	temp = ft_strchr(str, '#') - str;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			new2[i - temp + count] = str[i];
		i++;
	}
}

char	*toleft(char *str)
{
	char	*new;
	int		count;

	new = empty_square(4);
	count = 0;
	while (check_symb(new, 4) == 0)
	{
		free(new);
		new = empty_square(4);
		hesh(&new, str, count);
		count++;
	}
	return (new);
}
