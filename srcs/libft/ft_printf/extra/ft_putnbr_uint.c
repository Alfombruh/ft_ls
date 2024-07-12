/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfombra <alfombra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:56:45 by jofernan          #+#    #+#             */
/*   Updated: 2024/07/11 19:50:48 by alfombra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int ft_putnbr_uint(unsigned int n)
{
	unsigned int i;

	i = 1;
	if (n > 9)
		i += ft_putnbr_int((n / 10));
	i += ft_putchar_int((n % 10) + '0');
	return (i - 1);
}
