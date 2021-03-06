/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:40:04 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/23 19:55:00 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "read_grid.h"
#include "ft_fdf.h"

int		main(int argc, char **argv)
{
	int file;

	if (argc != 2)
		return (0);
	if (argv[1] == NULL)
		return (0);
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		return (0);
	init_fdf(read_grid(argv[1]), get_file_dimensions(argv[1]));
	return (0);
}
