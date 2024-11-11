/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:35:02 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/11 18:06:31 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

int	main(void)
{
	t_data	*data;

	data = ft_init_data();
	if (!data)
		return (EXIT_FAILURE);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop_hook(data->mlx, ft_input, data);
	mlx_loop_hook(data->mlx, ft_loop, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free(data);
	return (EXIT_SUCCESS);
}

// 11111
// 10101
// 10001
// 10N01
// 11111
