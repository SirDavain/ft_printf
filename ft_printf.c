/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:57:57 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/25 15:52:58 by dulrich          ###   ########.fr       */
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
	int	len;

	if (!str)
	{
		write(1,"(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
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

int	ft_putnbr(int n)
{
	char	*nbr;
	int		len;

	len = 0;
	nbr = ft_itoa(n);
	len = ft_putstr(nbr);
	free(nbr);
	return (len);
}

int	ft_unsigned_putnbr(int n)
{
	int		len;
	char	*nbr;

	len = 0;
	nbr = ft_unsigned_itoa(n);
	len = ft_putstr(nbr);
	free(nbr);
	return (len);
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

void	ft_putptr(uintptr_t p)
{
	if (p >= 16)
	{
		ft_putptr(p / 16);
		ft_putptr(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar(p + '0');
		else
			ft_putchar(p - 10 + 'a');
	}
}

int	ft_ptr_len(uintptr_t p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		len++;
		p /= 16;
	}
	return (len);
}

int	ft_printptr(uintptr_t p)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (p == 0)
		len += write(1, "0", 1);
	else
	{
		ft_putptr(p);
		len += ft_ptr_len(p);
	}
	return (len);
}

int	ft_check_format(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_printptr(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_len += ft_putpercent();
	return (print_len);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		print_len;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	print_len = 0;
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

#include <stdio.h>

int main(void)
{
	char	*arr;

	arr = "Hello world";
	ft_printf("%p", arr);
	printf("%p", arr);
	return (0);
}