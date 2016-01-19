/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:18:32 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/19 22:28:11 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_grid.h"
#include "mlx.h"
#include "ft_fdf.h"
#include <unistd.h>

void *mlx;
void *win;

unsigned int rand_interval(unsigned int min, unsigned int max)
{
	int r;
	const unsigned int range = 1 + max - min;
	const unsigned int buckets = 10000 / range;
	const unsigned int limit = buckets * range;

	/* Create equal size buckets all in a row, then fire randomly towards
	 *      * the buckets until you land in one of them. All buckets are equally
	 *           * likely. If you land off the end of the line of buckets, try again. */
	do
	{
		r = rand();
	} while (r >= limit);

	return min + (r / buckets);
}

int		init_fdf(int **tab)
{
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "Fil de fer");
	t_point a, b;
	a.x = 0;
	a.y = 0;
	b.x = 500;
	b.y = 600;
	//draw_line(mlx, win, a, b, 0xFFFFFF);
	//mlx_loop_hook(mlx, random_star, 0);
	draw_grid(mlx, win, tab);
	mlx_loop(mlx);
	return (1);
}
