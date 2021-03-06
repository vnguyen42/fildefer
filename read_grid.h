/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_grid.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:42:13 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/16 15:38:25 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_GRID_H
# define READ_GRID_H
# include <mlx.h>
# include <fcntl.h>

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

int				**read_grid(char *filepath);
t_point			get_file_dimensions(char *filepath);

#endif
