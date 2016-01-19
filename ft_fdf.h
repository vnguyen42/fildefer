/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:21:33 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/19 22:26:09 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_FDF_H
#define FT_FDF_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "read_grid.h"

int		init_fdf(int **tab);
void	draw_line(void *mlx, void *win, t_point a, t_point b, int color);
void	draw_grid(void *mlx, void *win, int **tab);

#endif
