/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 19:07:15 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 16:46:07 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "read_grid.h"
#include <stdio.h>

void	clear_screen(t_env *env)
{
	t_point p;

	mlx_clear_window(env->mlx, env->win);
	return;
	p.y = 0;
	while (p.y < WIN_HEIGHT)
	{
		p.x = 0;
		while (p.x < WIN_WIDTH)
		{
			//mlx_pixel_put(env->mlx, env->win, p.x, p.y, 0xDCF1F7);
			mlx_pixel_put(env->mlx, env->win, p.x, p.y, 0x000000);
			p.x++;
		}
		p.y++;
	}
}

int		ft_altitude_color(int height, int color)
{
	return (color - (height * 100));
}

void	draw_line(t_env *env, t_point a, t_point b)
{
	int		i;
	t_line	line;

	line.x = b.x - a.x;
	line.y = b.y - a.y;
	line.length = sqrt(line.x * line.x + line.y * line.y);
	line.addx = line.x / line.length;
	line.addy = line.y / line.length;
	line.x = a.x;
	line.y = a.y;
	i = 0;
	while (i < line.length)
	{
		mlx_pixel_put(env->mlx, env->win, line.x + env->pos.x,
				line.y + env->pos.y, ft_altitude_color(a.z, env->color) -
				(i * ((ft_int_diff(a.z, b.z) * 20000) / line.length)));
		line.x += line.addx;
		line.y += line.addy;
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
		draw_line(env, ft_rotation(env, ft_projection(env, a, 0.5), env->rotation),
				ft_rotation(env, ft_projection(env, b, 0.5), env->rotation));
	b.y--;
	b.x++;
	b.z = tab[b.y][b.x];
	if (tab[pos.y] != 0 && tab[pos.y][pos.x + 1] != -42)
		draw_line(env, ft_rotation(env, ft_projection(env, a, 0.5), env->rotation),
				ft_rotation(env, ft_projection(env, b, 0.5), env->rotation));
}

void	draw_grid(t_env *env, int clear)
{
	t_point p;

	if (clear)
		clear_screen(env);
	p.x = 0;
	p.y = 0;
	p.z = 0;
	while (env->tab[p.y] != 0)
	{
		p.x = 0;
		while (env->tab[p.y][p.x] != -42)
		{
			point_360_drawing(env, env->tab, p);
			p.x++;
		}
		p.y++;
	}
}
