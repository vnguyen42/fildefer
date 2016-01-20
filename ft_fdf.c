/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:18:32 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/20 21:04:19 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_grid.h"
#include "mlx.h"
#include "ft_fdf.h"
#include <unistd.h>

void	close_function(void *win)
{
	
}

int		init_fdf(int **tab)
{
	t_env env;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "Fil de fer");
	t_point a, b;
	a.x = 0;
	a.y = 0;
	b.x = 500;
	b.y = 600;
	env.rotation = 101;
	//draw_line(mlx, win, a, b, 0xFFFFFF);
	//mlx_loop_hook(mlx, random_star, 0);
	draw_grid(&env, tab);
	mlx_key_hook(env.win, ft_key_handler, &env);
	mlx_loop(env.mlx);
	return (1);
}
