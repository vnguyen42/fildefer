/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:30:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/02/25 11:47:52 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "read_grid.h"
#include "get_next_line.h"
#include <stdio.h>

int		get_next_number(char *str, int *index)
{
	int number_len;
	char *num;

	number_len = 0;
	num = NULL;
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

void	ft_strsplit_int(char *line, int *int_tab)
{
	int n_l;
	int index;
	int index_num;

	index = 0;
	index_num = 0;
	while (line[index] != '\0')
	{
		n_l = 0;
		while (line[index + n_l] != '\0' && line[index + n_l] >= '0' && line[index + n_l] <= '9')
			n_l++;
		if (n_l >= 1)
		{
			int_tab[index_num] = ft_atoi(ft_strsub(line, index, n_l));
			index_num++;
		}
		index += n_l;
		index++;
	}
	int_tab[index_num] = -43;
}

void	char_to_int_tab(char **tab, int **int_tab)
{
	t_point p;

	p.y = 0;
	while (tab[p.y] != 0)
	{
		ft_strsplit_int(tab[p.y], int_tab[p.y]); 
		p.y++;
	}
	int_tab[p.y][p.x] = -42;
}

char **char_tab_from_file(char *filepath)
{
	int file;
	char buf[5000];
	int index;
	t_point pos;
	char **tab;

	file = open(filepath, O_RDONLY);
	index = read(file, buf, 5000);
	buf[index] = '\0';
	close(file);
	pos.x = 0;
	pos.y = 0;
	while (buf[pos.x] != '\n')
		pos.x++;
	pos.y = index/pos.x;
	tab = (char **)malloc(sizeof(char*) * pos.y + 1);
	index = 0;
	while (index < pos.y)
	{
		tab[index] = (char*)malloc(sizeof(char) * (pos.x + 1));
		index++;
	}
	tab[index] = 0;
	return (tab);
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
	num = 0;
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
	char		**tab2;
	t_point		stop;

	file = open(filepath, O_RDONLY);
	index = read(file, buf, 5000);
	buf[index] = '\0';
	if (file == -1)
		return (NULL);
	tab = new_tab_from_file(filepath);
	tab2 = char_tab_from_file(filepath);
	close (file);
	file = open (filepath, O_RDONLY);
	stop.y = 0;
	while (get_next_line(file, &tab2[stop.y]))
	{
		stop.y++;
	}
	tab2[stop.y] = 0;
	char_to_int_tab(tab2, tab);
	t_point test;
	test.x = 0;
	test.y = 0;
	while (tab[test.y] != 0)
	{
		test.x = 0;
		while (tab[test.y][test.x] != 43)
		{
			printf("line %d: %d\n", test.y, tab[test.y][test.x]);
			test.x++;
		}
		test.y++;
	}
	close (file);
	return (tab);
	fill_tab_from_buf(tab, buf);
	return (tab);
	t_point p;
	p.x = 0;
	p.y = 0;
	while (tab[p.y] != 0)
	{
		p.x = 0;
		while (tab[p.y][p.x] != -43)
		{
			printf("%d ", tab[p.y][p.x]);
			p.x++;
		}
		printf("\n");
		p.y++;
	}
	return (tab);
}
