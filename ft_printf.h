#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int 	ft_printf(const char *, ...);
char	*ft_itoa(int n);

#endif