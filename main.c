/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:40:04 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/17 19:54:27 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "read_grid.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (argv[1] == NULL)
		return (0);
	read_grid(argv[1]);
	return (0);
}