/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:46:46 by aliferre          #+#    #+#             */
/*   Updated: 2024/11/22 18:57:10 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	check_args(argc, argv);
	data = ft_init_cub(argv[1]);
	if (!data
		|| mlx_image_to_window(data->mlx, data->img, 0, 0) == -1
		|| !mlx_loop_hook(data->mlx, ft_input, data)
		|| !mlx_loop_hook(data->mlx, ft_loop, data))
		return (EXIT_FAILURE);
	mlx_loop(data->mlx);
	ft_free_data(data);
	return (EXIT_SUCCESS);
}
