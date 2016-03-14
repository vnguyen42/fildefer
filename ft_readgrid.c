/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:30:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/11 19:48:34 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "read_grid.h"
#include "get_next_line.h"
#include <stdio.h>

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

t_point get_file_dimensions(char *filepath)
{
	int file;
	char buf[100];
	int line_length;
	t_point dimensions;

	line_length = 0;
	dimensions.x = 0;
	dimensions.y = 0;
	file = open(filepath, O_RDONLY);
	while (read(file, buf, 1) > 0)
	{
		if (buf[0] >= '0' && buf[0] <= '9')
			line_length++;
		if (buf[0] == '\n')
		{
			if (line_length > dimensions.x)
				dimensions.x = line_length;
			line_length = 0;
			dimensions.y++;
		}
	}
	return dimensions;
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

int		**read_grid(char *filepath)
{
	int 		file;
	int 		**int_tab;
	char		**char_tab;

	file = open(filepath, O_RDONLY);
	if (file == -1)
		return (NULL);
	
	t_point dimensions = get_file_dimensions(filepath);
	printf("dimensions: %d %d", dimensions.x, dimensions.y);
	return NULL;
	int_tab = new_tab_from_file(filepath);
	char_tab = char_tab_from_file(filepath);
	close (file);
	//	while (get_next_line(file, &tab2[stop.y]))
}
