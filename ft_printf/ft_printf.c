#include "ftprintf.h"

int	print_str(const char *str);
int	print_revstr(const char *str);

t_bool ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return(true);
	return (false);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

char	*inttostr(int n)
{
	return (ft_itoa(n));
}

int		ft_printchar(const char c)
{
	write(1, &c, 1);
	return (1);
}
/*
int		decimaltooctal(int n)
{
	char	*str;
	str = ft_itoa(n);
}
*/

char	*doubletostr(double n)
{
	char	*str;
	int 	x;
	int		i;
	   	
	i = 0;
	x = (int)n;
	str = ft_strjoin(ft_itoa(x),".");
	if(!str)
	{
		ft_memdel((void**)&str);
		exit(EXIT_FAILURE);
	}
	while (i < 6)
	{
		n = n - (double)x;
		n = n * 10;
		if (x < 0)
			str = ft_strjoin(str,ft_itoa(n * -1));
		else
			str = ft_strjoin(str,ft_itoa(n * 1));
		if(!str)
		{
			ft_memdel((void**)&str);
			exit(EXIT_FAILURE);
		}
		x = (int)n;
		i++;
	}
	return(str);
}

int		decimaltohexoroct(int c, char a)
{
	char	*str;
	int		index;
	int coef;

	coef = 8;
	index = 0 ;
	str = ft_strnew(sizeof(char) * 100);
	if (!str)
	{
		ft_memdel((void **)&str);
		exit(EXIT_FAILURE);
	}
	if (a == 'x' || a == 'X')
		coef = 16;
	while (c != 0)
	{
		if (a == 'x' || a == 'X')
			str[index] = hexa[c % 16];
		else if (a == 'o')
			str = ft_strjoin(str, ft_itoa(c % 8));
		if (ft_isupper(a))
			str[index] = ft_toupper(str[index]);
		c = c / coef;
		index++;
	}
	index = 0;
	index = print_revstr(str);
	ft_memdel((void**)&str);
	return(index);
}

int	print_revstr(const char *str)
{
	int	index;

	index = ft_strlen(str);
	while (index >= 0)
	{
		write(1, &str[index], 1);
		index--;
	}
	return (ft_strlen(str));
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
	else if (c == 'd' || c == 'i')
		return (strlength += print_str(inttostr(va_arg(ap, int))));
	else if (c == 'c')
		return(strlength += ft_printchar(va_arg(ap, int)));
	else if (c == 'f')
		return(strlength += print_str(doubletostr(va_arg(ap, double))));
	else if (c == 'x' || c == 'X')
		return (strlength += decimaltohexoroct(va_arg(ap,int), c));
	else if (c == 'o')
		return (strlength += decimaltohexoroct(va_arg(ap, unsigned int), c));
	else if (c == '%')
		return (strlength += ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		length;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	length = 0;
	while( format[i] != '\0')
	{
		if (format[i] == '%')
		{
			length += check_option(ap, format[i + 1]);
			i++;
		}
		else
			length += ft_printchar(format[i]);
		i++;
	}
	va_end(ap);
	return (length);
}