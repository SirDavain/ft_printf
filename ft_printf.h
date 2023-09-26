#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int 	ft_printf(const char *, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_check_format(va_list args, const char format);
void	ft_putptr(uintptr_t p);
int		ft_ptr_len(uintptr_t p);
int		ft_printptr(uintptr_t p);
int		ft_hex_len(unsigned int n);
void	ft_puthex(unsigned int n, const char format);
int		ft_printhex(unsigned int n, const char format);
int		ft_putpercent(void);
int		ft_count_unum(unsigned int n);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_putnbr(int n);
int		ft_unsigned_putnbr(int n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
#endif