/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliferre <aliferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:46:46 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/11 18:53:18 by aliferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_data	*data;

	data = ft_init_data();
	if (!data
		|| mlx_image_to_window(data->mlx, data->img, 0, 0) == -1
		|| !mlx_loop_hook(data->mlx, ft_input, data)
		|| !mlx_loop_hook(data->mlx, ft_loop, data))
		return (EXIT_FAILURE);
	mlx_loop(data->mlx);
	ft_free_data(data);
	return (EXIT_SUCCESS);
}
