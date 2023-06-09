/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:39:10 by pvital-m          #+#    #+#             */
/*   Updated: 2023/04/02 21:44:36 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(long int n)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	len = ft_strlen(s);
	ft_printf("%s", s);
	free(s);
	return (len);
}

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int nbr)
{
	int		_len;
	char	*num;

	_len = 0;
	if (nbr == 0)
		_len += write(1, "0", 1);
	else
	{
		num = ft_utoa(nbr);
		_len += ft_print_str(num);
		free(num);
	}
	return (_len);
}
