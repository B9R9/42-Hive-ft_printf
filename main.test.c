#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"



void	print( char *str, ...)
{
	char	*contain;

	contain = "hello";
	contain = contain + str;
/*
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
	
	va_end(args);*/
	printf("%s", contain);
	printf("%s", str);

}

int	main(void)
{

	/*Checker le retour de la function
	 * printf renvoie un int qui correspond au nombre de lettre imprimee sans \0*/
	printf("Retour de printf= %d\n",printf("Hello\n"));



	char *ex;
	ex = strdup("Test\n");
	print("valeur de str : %s et elle contient %d\n", ex, ft_strlen(ex));


	return (EXIT_SUCCESS);
}