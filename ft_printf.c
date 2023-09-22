/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:57:57 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/22 13:16:24 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_check_format(va_list args, char *str)
{
	if (*format == 'c')
		c = va_arg(args, int);
	else if (format[i] == 's')
		ft_putstr();
	else if (format[i] == 'p')
		ft_putptr;
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr;
	else if (format[i] == 'u')
		ft_putun_nbr;
	else if (format[i] == 'x')
		ft_puthex_lower;
	else if (format[i] == 'X')
		ft_puthex_upper;
	else if (format[i] == '%')
		write(1, '%', 1);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		print_len;

	i = 0;
	if (!str[i])
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_check_format(args, str[i] + 1);
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

/*Use variadic args to make the base functionality of printf
It should notice the nbr of args given and act accordingly
If it for example says %c, it should know to print a char
The function should also be able to print multiple different
arg types (e.g. int, char and string)
I need a loop to go through the string a the beginning, specifying
the different types to print.
Return value: the number of chars to be printed / on failure: neg nbr

*/