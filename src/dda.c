/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:06:39 by rvaz              #+#    #+#             */
/*   Updated: 2024/01/24 17:14:45 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_2d_point	dda_def_step_ray(t_player player, t_2d_point step_size,
		t_2d_point *ray, t_2d_point *step)
{
	if (player.dir.x < 0)
	{
		step->x = -1;
		ray->x = (player.pos.x - ceil(player.pos.x)) * step_size.x;
	}
	else
	{
		step->x = 1;
		ray->x = ((ceil(player.pos.x) + 1) - player.pos.x) * step_size.x;
	}
	if (player.dir.y < 0)
	{
		step->y = -1;
		ray->y = (player.pos.y - ceil(player.pos.y)) * step_size.y;
	}
	else
	{
		step->y = 1;
		ray->y = ((ceil(player.pos.y) + 1) - player.pos.y) * step_size.y;
	}
}

double	dda(t_2d_point start, t_2d_point dir, t_data data)
{
	t_2d_point	current;
	t_2d_point	step_size;
	t_2d_point	step;
	t_2d_point	ray_len;
	double		dist;

	dist = 0;
	step_size.x = sqrt(1 + (dir.y / dir.x) * (dir.y / dir.x));
	step_size.y = sqrt(1 + (dir.x / dir.y) * (dir.x / dir.y));
	current = (t_2d_point){(int)start.x, (int)start.y};
	dda_def_step_ray(*data.player, step_size, &ray_len, &step);
	// Make functions for these checks \/ (is_wall() && is_inside_map())
	while (data.map[(int)current.y][(int)current.x] != '1' && current.x < data.map_size.x && current.y < data.map_size.y)
	{
		if (ray_len.x < ray_len.y)
		{
			current.x += step.x;
			dist = ray_len.x;
			ray_len.x += step_size.x;
		}
		else
		{
			current.y += step.y;
			dist = ray_len.y;
			ray_len.y += step_size.y;
		}
	}
	return (dist);
}