/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:57:57 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/25 14:07:35 by dulrich          ###   ########.fr       */
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

int	ft_printstr(char *str)
{
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
}

int	ft_putnbr(int n)
{
	char	*nbr;
	int		len;

	len = 0;
	nbr = ft_itoa(n);
	len = ft_printstr(nbr);
	free(nbr);
	return (len);
}

int	unsigned_putnbr(int n)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = ft_unsigned_itoa(n);
	len = ft_printstr(nbr);
	free(nbr);
	return (len);
}

int	ft_count_unum(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	int	len;
	char	*nbr;

	len = ft_count_unum(n);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (n > 0)
	{
		nbr[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (nbr);
}

int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_puthex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar((n + '0'));
		}
		else
		{
			if (format == 'X')
				ft_putchar(n - 10 + 'A');
			else if (format == 'x')
				ft_putchar(n - 10 + 'a');
		}
	}
}

int	ft_printhex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(n, format);
	return (ft_hex_len(n));
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
		print_len += ft_unsigned_putnbr(va_arg(args, unsigned int));
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
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_check_format(args, str[i] + 1);
			i++;
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