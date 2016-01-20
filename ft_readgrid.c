/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:30:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/20 18:24:52 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "read_grid.h"
#include <stdio.h>

int		get_next_number(char *str, int *index)
{
	int number_len;
	char *num;

	number_len = 0;
	while (str[*index] != '\0' && (str[*index] < '0' || str[*index] > '9'))
	{
		if (str[*index] == '\n')
		{
			(*index)++;
			return (-43);
		}
		(*index)++;
	}
	if (str[*index] == '\0')
		return (-42);
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		number_len++;
		(*index)++;
	}
	if (number_len != 0)
		num = ft_strsub(str, *index - number_len, number_len);
	return (ft_atoi(num));
}

int **new_tab_from_file(char *filepath)
{
	int file;
	char buf[5000];
	int index;
	t_point pos;
	int **tab;

	file = open(filepath, O_RDONLY);
	index = read(file, buf, 5000);
	buf[index] = '\0';
	close(file);
	pos.x = 0;
	pos.y = 0;
	while (buf[pos.x] != '\n')
		pos.x++;
	pos.y = index/pos.x;
	tab = (int **)malloc(sizeof(int*) * pos.y + 1);
	index = 0;
	while (index < pos.y)
	{
		tab[index] = (int*)malloc(sizeof(int) * (pos.x + 1));
		index++;
	}
	tab[index] = 0;
	return (tab);
}

void	fill_tab_from_buf(int **tab, char buf[5000])
{
	t_point pos;
	int		index;
	int		num;

	index = 0;
	pos.x = 0;
	pos.y = 0;
	while (num != -42)
	{
		num = get_next_number(buf, &index);
		if (num == -43)
		{
			tab[pos.y][pos.x] = -42;
			pos.y++;
			pos.x = 0;
		}
		else if (num == -42)
			tab[pos.y][pos.x] = -42;
		else
		{
			tab[pos.y][pos.x] = num;
			pos.x++;
		}
	}
}

int		**read_grid(char *filepath)
{
	int 		file;
	char		buf[5000];
	int			index;
	int 		**tab;
	t_point		stop;

	file = open(filepath, O_RDONLY);
	index = read(file, buf, 5000);
	buf[index] = '\0';
	close(file);
	if (file == -1)
		return (NULL);
	tab = new_tab_from_file(filepath);
	fill_tab_from_buf(tab, buf);
	return (tab);
	t_point p;
	p.x = 0;
	p.y = 0;
	while (tab[p.y] != 0)
	{
		p.x = 0;
		while (tab[p.y][p.x] != -42)
		{
			printf("%d ", tab[p.y][p.x]);
			p.x++;
		}
		printf("\n");
		p.y++;
	}
	return (tab);
}
