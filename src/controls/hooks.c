/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:44:31 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/03 15:31:07 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Runs every tick, and updates the player's position and view
*/
int	game_update(t_data *data)
{
	if (!data->player.move && !data->player.move_cam)
		return (1);
	if (data->player.move)
		move_player(data);
	if (data->player.move_cam)
	{
		rotate_player(data);
		vertical_movement(data);
		adjust_fov(data);
	}
	update_view(data);
	return (0);
}

/**
 * @brief Detects user input
*/
int	key_reader(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_pgm(data);
	else if (keycode == MOVE_FORWARD || keycode == MOVE_BACK
		|| keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
		set_move(keycode, data);
	else if (keycode == ZOOM_OUT || keycode == ZOOM_IN || keycode == ROT
		|| keycode == RROT || keycode == ZOOM_IN || keycode == ZOOM_OUT
		|| keycode == LOOK_UP || keycode == LOOK_DOWN)
		set_move_cam(keycode, data);
	return (0);
}

/**
 * @brief Detects when a key is released
*/
int	key_release(int keycode, t_data *data)
{
	if (keycode == MOVE_FORWARD)
		data->player.move &= data->player.move ^ 1 << MOVE_FORWARD_B;
	else if (keycode == MOVE_BACK)
		data->player.move &= data->player.move ^ (1 << MOVE_BACK_B);
	else if (keycode == MOVE_LEFT)
		data->player.move &= data->player.move ^ (1 << MOVE_LEFT_B);
	else if (keycode == MOVE_RIGHT)
		data->player.move &= data->player.move ^ (1 << MOVE_RIGHT_B);
	else if (keycode == ROT)
		data->player.move_cam &= data->player.move_cam ^ 1 << ROT_B;
	else if (keycode == RROT)
		data->player.move_cam &= data->player.move_cam ^ 1 << RROT_B;
	else if (keycode == ZOOM_OUT)
		data->player.move_cam &= data->player.move_cam ^ 1 << ZOOM_OUT_B;
	else if (keycode == ZOOM_IN)
		data->player.move_cam &= data->player.move_cam ^ 1 << ZOOM_IN_B;
	else if (keycode == LOOK_UP)
		data->player.move_cam &= data->player.move_cam ^ 1 << LOOK_UP_B;
	else if (keycode == LOOK_DOWN)
		data->player.move_cam &= data->player.move_cam ^ 1 << LOOK_DOWN_B;
	return (0);
}

int	close_pgm(t_data *data)
{
	free_and_exit(data, MSG_EXIT, 0);
	return (0);
}
