/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:41:31 by pvital-m          #+#    #+#             */
/*   Updated: 2023/06/09 13:54:20 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	index;
	int	len;

	len = 0;
	index = 0;
	if (str == NULL)
	{
		len += ft_print_str("(null)");
	}
	else
	{
		while (str[index] != 0)
		{
			ft_print_char(str[index]);
			len++;
			index++;
		}
	}
	return (len);
}
