#include "ft_printf.h"
#define RED "\x18[31m"
#define NORMAL "\x1B[0m"

int	main(void)
{
	int i;
	int q = 3;
	int r = 2;
	int s = 1;
	long double j;
	char	str[]= "Thank you Jonas!";
	size_t a;
	long int b;
	char	c;
	unsigned int x = 255;

	c = 65;
	i = 10;
	a = 15;
	b = 123456890123456789;
	j = 3.142165131313113;
	ft_printf("Hello Jona!\n");
	ft_printf("Number: %d | %d |%d |%d\n", i, q, r ,s);
	ft_printf("My string:%5s\nsize_t: %d\nfloat:%f\n", str, a, j);
	ft_printf("Pointer:%p\n", &a);
	printf("My string:%5s\n", str);
	ft_printf("%%\n");

	ft_printf("My char: %c\nMy %%i: %i\nMyOcto: %o\nMy uint: %u\n", c, i, i, x);
	ft_printf("XDecimal: %x\n Big X: %X\n", i, i);


	ft_printf("%c | %d |%d| %c\n", c,i, i, c);

	//ft_printf("%hd|| %hhd | %ld || %lld", d, i,  , b);
	ft_printf("Jonas: %Lf\n", j);
	printf("Origin: %Lf\n", j);

	ft_printf("%.55d\n", 16091985);
	ft_printf("%.*d\n", 55, 55);

	ft_printf("%sHello%s\n", RED, NORMAL);

	return (0);
}
