#include "libft.h"

int	ft_printbits(void *ptr, int size)
{
	u_int8_t		*data;
	size_t		count;
	u_int8_t		i;
	u_int8_t		lu;

	lu = 1;
	count = 0;
	data = (u_int8_t*)(ptr) + (size - 1);
	while ((int)count < size)
	{
		i = 0;
		while (i < 8)
		{
			if (*data & (lu << (7- i)))
				write(1, "1", 1);
			else
				write(1, "0", 1);
			i++;
		}
		write (1, " ", 1);
		data--;
		count++;
	}
	return (0);
}


// {
//     unsigned char *b;
//     unsigned char byte;
//     int i;
// 	int	j;

// 	b = (unsigned char*) ptr;
// 	i = size - 1;
// 	j = 7;

// 	while(i >= 0)
// 	{
// 		while(j>= 0)
// 		{
// 			byte = (b[i] >> j) & 1;
// 			printf("%u",byte);
// 			j--;
// 		}
// 		i--;
// 	}
// 	return (0);
// }
/*
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            ft_putnbr(byte);
        }
    }
    puts("");
}
*/
