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
	size_t		index;
	size_t		lastone;
	char	*containeur[5];
	int x = 0;
	index = 0;
	va_list ap;
	va_start(ap,str);

	if (!str)
		printf("STR == NULL imprimer l usage de la fucntion");
	lastone = 0;
	while (str[index] != '\0')
	{
		index = index_of(str, lastone);
		containeur[x] = ft_strsub(str, lastone, index - lastone);
		lastone = index + 2;
		x++;
		if (str[index + 1] == 's')
			{
				containeur[x] = ft_strdup(va_arg(ap,char *));
				lastone = index + 2;
				x++;
			}
	}
	va_end(ap);
	x = 0;
	while(x < 4)
		printf("%s", containeur[x++]);



	return (1);
}