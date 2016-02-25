/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:47:06 by vnguyen           #+#    #+#             */
/*   Updated: 2016/02/25 11:09:48 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "read_grid.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int ft_key_handler(int keycode, void *param)
{
	t_env *env;

	env = param;
	printf("key event %d\n", keycode);
	if (keycode == 257)
		env->rotation -= 0.1;
	else if (keycode == 256)
		env->rotation += 0.1;
	else if (keycode == 69)
		env->grid_space+= 2;
	else if (keycode == 78 && env->grid_space >= 2)
		env->grid_space -= 2;
	else if (keycode == 126)
		env->pos.y -= 25;
	else if (keycode == 125)
		env->pos.y += 25;
	else if (keycode == 123)
		env->pos.x -= 25;
	else if (keycode == 124)
		env->pos.x += 25;
	if (keycode == 257 || keycode == 256 || keycode == 69 || keycode == 78
		|| (keycode >= 123 && keycode <= 126))
		draw_grid(param, 1);
	if (keycode == 53)
		exit(0);
	return (1);
}
