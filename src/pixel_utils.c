/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:19:55 by pvital-m          #+#    #+#             */
/*   Updated: 2023/05/30 17:07:35 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void show_fractal_data(){
	printf("%sFractal data:%s\n", YEL, RESET);
	printf("Zoom: %f\n", screen()->zoom);
	printf("Real part: %f\n", screen()->real_part);
	printf("Imaginary part: %f\n", screen()->imaginary_part);
	printf("Ratio x: %f\n", screen()->ratio_x);
	printf("Ratio y: %f\n", screen()->ratio_y);
	printf("Mouse x: %d\n", screen()->mouse_x);
	printf("Mouse y: %d\n", screen()->mouse_y);
	printf("Max iterations: %d\n", screen()->interactions);
	printf("Color mode: %d\n", screen()->color_mode);
	printf("Constant real part: %f\n", screen()->constant_a);
	printf("Constant Imaginary part: %f\n", screen()->constant_b);
	
}