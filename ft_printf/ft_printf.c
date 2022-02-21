#include "ftprintf.h"

char	*inttostr(int n)
{
	return (ft_itoa(n));
}
int		ft_printchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		write(1, &str[index++], 1);
	return (index);
}

int		check_option(va_list ap, const char c)
{
	int	strlength;

	strlength = 0;
	if (c == 's')
		return (strlength += print_str(va_arg(ap, char *)));
	else if (c == 'd')
		return (strlength += print_str(inttostr(va_arg(ap, int))));
	else if (c == 'c')
		return(strlength += ft_printchar(va_arg(ap, int)));
	else if (c == '%')
		return (strlength += ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	length = 0;
	while( str[i] != '\0')
	{
		if (str[i] == '%')
		{
			length += check_option(ap, str[i + 1]);
			i++;
		}
		else
			length += ft_printchar(str[i]);
		i++;
	}
	va_end(ap);
	return (length);
}