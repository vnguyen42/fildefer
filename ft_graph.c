/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 19:07:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/20 21:02:03 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "read_grid.h"
#include <stdio.h>

void	clear_screen(t_env *env)
{
	t_point p;

	p.y = 0;
	while (p.y < WIN_HEIGHT)
	{
		p.x = 0;
		while (p.x < WIN_WIDTH)
		{
			mlx_pixel_put(env->mlx, env->win, p.x, p.y, 0xDCF1F7);
			p.x++;
		}
		p.y++;
	}
}

void	draw_line(t_env *env, t_point a, t_point b, int color)
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
		mlx_pixel_put(env->mlx, env->win, x, y, color);
		x += addx;
		y += addy;
		i++;
	}
}

void	point_360_drawing(t_env *env, int **tab, t_point pos)
{
	t_point a;
	t_point b;

	a.x = pos.x;
	a.y = pos.y;
	a.z = tab[a.y][a.x];
	b.x = (pos.x);
	b.y = (pos.y + 1);
	b.z = tab[b.y][b.x];
	if (tab[pos.y + 2] != 0 && tab[pos.y + 1][pos.x] != -42)
		draw_line(env, ft_rotation(ft_projection(a, 0.5), env->rotation),
				ft_rotation(ft_projection(b, 0.5), env->rotation), 0xFFFFFF);
	b.y--;
	b.x++;
	b.z = tab[b.y][b.x];
	if (tab[pos.y] != 0 && tab[pos.y][pos.x + 1] != -42)
		draw_line(env, ft_rotation(ft_projection(a, 0.5), env->rotation),
				ft_rotation(ft_projection(b, 0.5), env->rotation), 0xFFFFFF);
}

void	draw_grid(t_env *env, int **tab)
{
	t_point p;

	clear_screen(env);
	p.x = 0;
	p.y = 0;
	p.z = 0;
	while (tab[p.y] != 0)
	{
		p.x = 0;
		while (tab[p.y][p.x] != -42)
		{
			point_360_drawing(env, tab, p);
			//printf("%d ", tab[p.y][p.x]);
			p.x++;
		}
		p.y++;
	}
}
