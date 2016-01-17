/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:30:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/17 20:29:57 by vnguyen          ###   ########.fr       */
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
		(*index)++;
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

int		read_grid(char *filepath)
{
	int 	file;
	char	buf[5000];
	int		index;

	file = open(filepath, O_RDONLY);
	index = read(file, buf, 5000);
	buf[index] = '\0';
	close(file);
	if (file == -1)
		return (-1);
	index = 0;

	char test[50] = "0 2 100 3 0";
	int stop = 0;
	while (stop != -42)
	{
		stop = get_next_number(test, &index);
		printf("\n%d", stop);
	}
	return (1);
}
