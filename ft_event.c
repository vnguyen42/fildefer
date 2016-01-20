/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:47:06 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/20 22:47:55 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "read_grid.h"
#include <math.h>

int ft_key_handler(int keycode, void *param)
{
	t_env *env;

	env = param;
	printf("key event %d\n", keycode);
	if (keycode == 123)
	{
		env->rotation -= 0.1;
		draw_grid(param, 1);
	}
	if (keycode == 124)
	{
		env->rotation += 0.1;
		draw_grid(param, 1);
	}
	if (keycode == 53)
		exit(0);
}
