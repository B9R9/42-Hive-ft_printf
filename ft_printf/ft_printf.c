#include "ftprintf.h"
/*
void	print( char *str, ...)
{
	char	*contain;

	contain = "hello";
	contain = contain + str;

	va_list args;
	va_start(args, str);
	while (str[i] != '\0')
	{
		delimiter = checkdelimiter();
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				contain = ft_strsub(str, 0 , i);
				contain = ft_strjoin(contain, va_arg(args,char *));
				i += 2;
			}
		}
		i++;
	}
	
	va_end(args);
	printf("%s", contain);
	printf("%s", str);

}
*/

static	int	index_of(const char *str, int index)
{

	while (str[index] != '%' && str[index] != '\0')
		index++;
	return (index);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		lenght;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	length = 0;
	while( str[i] != '\0')
	{
		if (str[i] == '%')
		{
			length += check_option(ap, str[i + 1]),
			i++,
		}
		else
			length += ft_printchar(str[i]);
		i++,
	}
	va_end(ap);
	return (length);
}