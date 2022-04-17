#include "ft_printf.h"

int	format_binary(t_parameter *option, void const *ptr)
{
	int size;
	(void)option;

	size = 0;
	size += ft_printbits( &ptr, sizeof(ptr));
	return (size);
}


int	argtovoid(t_parameter *li, va_list ap)
{
	return (format_binary(li,va_arg(ap, void *)));
}
