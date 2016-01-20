/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:21:33 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/20 20:57:36 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_FDF_H
#define FT_FDF_H
#define GRID_SPACE 30
#define WIN_WIDTH 1000
#define WIN_HEIGHT 1000
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "read_grid.h"

typedef struct		s_env
{
	void *mlx;
	void *win;
	float rotation;
}					t_env;

int		init_fdf(int **tab);
void	draw_line(t_env *env, t_point a, t_point b, int color);
void	draw_grid(t_env *env, int **tab);
t_point	ft_projection(t_point p, float cte);
t_point ft_rotation(t_point p, float angle);
int		ft_key_handler(int keycode, void *param);

#endif
