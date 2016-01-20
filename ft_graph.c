/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 19:07:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/20 18:07:55 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "read_grid.h"
#define GRID_SPACE 30

void	draw_line(void *mlx, void *win, t_point a, t_point b, int color)
{
	int i;
	double x;
	double y;
	double length;
	double addx;
	double addy;

	x = b.x - a.x;
	y = b.y - a.y;
	length = sqrt(x * x + y * y);
	addx = x / length;
	addy = y / length;
	x = a.x;
	y = a.y;
	i = 0;
	while (i < length)
	{
		mlx_pixel_put(mlx, win, x, y, color);
		x += addx;
		y += addy;
		i++;
	}
}

void	point_360_drawing(void *mlx, void *win, int **tab, t_point pos)
{
	t_point a;
	t_point b;

	a.x = pos.x * GRID_SPACE;
	a.y = pos.y * GRID_SPACE;
	b.x = (pos.x) * GRID_SPACE;
	b.y = (pos.y + 1) * GRID_SPACE;
	if (tab[pos.y + 2] != 0 && tab[pos.y + 1][pos.x] != -42)
		draw_line(mlx, win, a, b, 0xFFFFFF);
	b.y -= GRID_SPACE;
	b.x += GRID_SPACE;
	if (tab[pos.y] != 0 && tab[pos.y][pos.x + 1] != -42)
		draw_line(mlx, win, a, b, 0xFFFFFF);
}

void	draw_grid(void *mlx, void *win, int **tab)
{
	t_point p;

	p.x = 0;
	p.y = 0;
	while (tab[p.y] != 0)
	{
		p.x = 0;
		while (tab[p.y][p.x] != -42)
		{
			point_360_drawing(mlx, win, tab, p);
			//printf("%d ", tab[p.y][p.x]);
			p.x++;
		}
		printf("\n");
		p.y++;
	}
}
