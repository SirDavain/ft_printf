/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:57:57 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/22 17:00:29 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	char	*str;

	str = ft_itoa(n);
	return (str);
}

int	unsigned_putnbr(int n)
{
	
}

char	*unsigned_itoa(unsigned int n)
{
	
}

void	*ft_putptr()
{
	
}

int	ft_check_format(va_list args, const char format)
{
	int	print_len;

	if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_putun_nbr(va_arg(args, unsigned int));
	else if (format == 'x')
		print_len += ft_puthex_lower(va_arg(args, int));
	else if (format == 'X')
		print_len += ft_puthex_upper(va_arg(args, int));
	else if (format == '%')
		write(1, '%', 1);
	return (print_len);
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