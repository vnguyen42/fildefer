/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:30:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 16:46:32 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "read_grid.h"
#include "get_next_line.h"
#include <stdio.h>

int		number_of_numbers(char *line)
{
	int i;
	int j;
	int number_of_numbers;

	i = 0;
	number_of_numbers = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (line[i + j] >= '0' && line[i + j] <= '9')
			j++;
		i+= j;
		if (j > 0)
			number_of_numbers++;
		i++;
	}
	return (number_of_numbers);
}

t_point get_file_dimensions(char *filepath)
{
	int file;
	char *buf;
	int line_length;
	t_point dimensions;
	int i;

	line_length = 0;
	dimensions.x = 0;
	dimensions.y = 0;
	file = open(filepath, O_RDONLY);
	while (get_next_line(file, &buf) > 0)
	{
		if (number_of_numbers(buf) > dimensions.x)
			dimensions.x = number_of_numbers(buf);
		dimensions.y++;
		i = 0;
	}
	return dimensions;
}

int		**intnew(t_point dimensions)
{
	int **tab;
	int i;

	tab = NULL;
	i = 0;
	tab = (int**)malloc(sizeof(int*) * dimensions.y);
	while (i <= dimensions.y)
	{
		tab[i] = (int*)malloc(sizeof(int) * dimensions.x);
		i++;
	}
	return (tab);
}

int		get_next_number(char *line, int *num)
{
	int i;
	int j;

	i = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (line[i + j] >= '0' && line[i + j] <= '9')
			j++;
		if (j > 0)
		{
			*num = ft_atoi(ft_strsub(line, i, j));
			return j;
		}
		i += j;
		i++;
	}
	*num = -42;
	return (-42);
}

int		**get_tab_from_file(char *filepath)
{
	t_point i;
	t_point j;
	int file;
	char *buf;
	int **tab;

	i.x = 0;
	i.y = 0;
	file = open(filepath, O_RDONLY);
	tab = intnew(get_file_dimensions(filepath));
	while (get_next_line(file, &buf) > 0)
	{
		i.x = 0;
		j.x = 0;
		j.y = 0;
		while (j.x != -42)
		{
			j.x = get_next_number(&buf[j.y], &tab[i.y][i.x]);	
			j.y += j.x;
			j.y++;
			i.x++;
		}
		i.y++;
	}
	tab[i.y] = 0;
	return (tab);
}

void	ft_print_grid(int **tab)
{
	t_point c;

	c.x = 0;
	c.y = 0;
	while (tab[c.y] != 0)
	{
		c.x = 0;
		while (tab[c.y][c.x] != -42)
		{
			printf("%d ", tab[c.y][c.x]);
			c.x++;
		}
		c.y++;
		printf("\n");
	}
}

int		**read_grid(char *filepath)
{
	int 		file;
	int 		**int_tab;

	file = open(filepath, O_RDONLY);
	if (file == -1)
		return (NULL);
	
	t_point dimensions = get_file_dimensions(filepath);
	printf("dimensions: %d %d", dimensions.x, dimensions.y);
	int_tab = get_tab_from_file(filepath);
	close (file);
	printf("\n");
	ft_print_grid(int_tab);
	return (int_tab);
}
