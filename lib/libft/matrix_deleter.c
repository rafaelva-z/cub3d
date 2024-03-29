/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_deleter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:04:04 by fda-estr          #+#    #+#             */
/*   Updated: 2024/01/26 02:06:00 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matrix_deleter(char ***mtx)
{
	int	i;

	i = 0;
	if (!mtx || !*mtx)
		return ;
	while ((*mtx)[i])
	{
		free((*mtx)[i]);
		(*mtx)[i++] = NULL;
	}
	free(*mtx);
	*mtx = NULL;
}
