#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void	print(const char *str, ...)
{
	char	*ex;
	va_list args;
	va_start(args, str);
	ex = va_arg(args, char *);
	write (1, ex, strlen(ex));
	ex = va_arg(args, char *);
	write (1, ex, strlen(ex));
	va_end(args);

}

int	main(void)
{

	/*Checker le retour de la function
	 * printf renvoie un int qui correspond au nombre de lettre imprimee sans \0*/
	printf("Retour de printf= %d\n",printf("Hello\n"));



	char *ex;
	ex = strdup("Test\n");
	print("Hello\n", ex, "Aargu 1\n");


	return (EXIT_SUCCESS);
}