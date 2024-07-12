/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <jofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:57:17 by jofernan          #+#    #+#             */
/*   Updated: 2021/08/14 18:02:05 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/ft_printf.h"

int	write_string(va_list op)
{
	int		i;
	char	*c;

	c = va_arg(op, char *);
	if (c == NULL)
		return (write(1, "(null)", 6));
	i = ft_putstr_int(c);
	return (i);
}
