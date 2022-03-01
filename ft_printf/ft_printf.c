#include "ftprintf.h"

int	print_str(const char *str);
int	print_revstr(const char *str, char c);

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

int		decimaltohexoroct(unsigned int c, char a)
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
		if (!str)
		{
			ft_memdel((void **)&str);
			exit(EXIT_FAILURE);
		}
		if (ft_isupper(a))
			str[index] = ft_toupper(str[index]);
		c  = c / coef;
		index++;
	}
	index = 0;
	index = print_revstr(str, a);
	ft_memdel((void**)&str);
	return(index);
}

int		printpointeraddress(unsigned long long int c)
{
	char	*str;
	int		index;

	index = 0 ;
	str = ft_strnew(sizeof(char) * 100);
	if (!str)
	{
		ft_memdel((void **)&str);
		exit(EXIT_FAILURE);
	}
	if (c == 0)
		str[0] = '0';
	while (c != 0)
	{
			str[index] = hexa[c % 16];
		if (!str)
		{
			ft_memdel((void **)&str);
			exit(EXIT_FAILURE);
		}
		c  = c / 16;
		index++;
	}
	index = 0;
	index = print_revstr(str, 'p');
	ft_memdel((void**)&str);
	return(index);
}


int	print_revstr(const char *str, char c)
{
	int	index;
	
	if (c == 'p')
		str = ft_strjoin(str,"x0");
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

//Can't print a int //'
int	printbit(const unsigned char *ptr)
{
	int				count;
	int				i;
	unsigned char 	bit;
	unsigned char 	*b;

	printf("%s\n", ptr);

	i = 0;
	count = 0;
	bit = 1 << 7;
	b = (unsigned char *)ptr;
	while (b[i] != '\0')
	{
		while (bit != 0)
		{
			if (b[i] & bit)
				count += ft_printchar('1');
			else
				count += ft_printchar('0');
			bit >>= 1;
		}
		i++;
		count +=ft_printchar(' ');
		bit = 0;
		bit = 1 << 7;
	}
	return (count);
}

int	printunsignedint(unsigned int c)
{
	char *str;
	int count;

	count = 0;
	 if (c < 0)
	{
		str = ft_itoa(maxuint - c);
		count = print_str(str);
	}
	 else
		 str = ft_itoa(c);
	 count = print_str(str);
	return (count);
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
		return (strlength += decimaltohexoroct(va_arg(ap,unsigned int), c));
	else if (c == 'o')
		return (strlength += decimaltohexoroct(va_arg(ap, unsigned int), c));
	else if(c == 'b')
		return (strlength += printbit(va_arg(ap, unsigned char*)));
	else if (c == 'u')
		return (strlength += printunsignedint(va_arg(ap, unsigned int)));
	else if (c == 'p')
		return (strlength += printpointeraddress(va_arg(ap,unsigned long long int)));
	else if (c == '%')
		return (strlength += ft_printchar('%'));
	return (0);
}

t_bool	checkparams(char c)
{
	size_t	i;

	i = 0;
	printf("Valeur de c = %c\n", c);
	while(params[i] != '\0')
	{
		if (c == params[i])
			return(false);
		i++;
	}
	return (true);
}

void	parameter(const char *str, int index)
{
	int	start;
	
	printf("Valeur de index = %d\n", index);
	start = index;
	index = index + 1;
	while(checkparams(str[index]))
	{
		index++;
	}
	printf("%d(index) - %d(start) = %d\n", index, start, index - start);
	printf("PARAMSS = %s\n", ft_strsub(str, start, (index + 1) - start));

//	return (ft_strsub(str,start, index - start));
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
			parameter(format, i);
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