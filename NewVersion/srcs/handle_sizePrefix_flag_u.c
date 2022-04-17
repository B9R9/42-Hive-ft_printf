#include "ft_printf.h"

int	u_ll_itoa(t_parameter *option, unsigned long long int number)
{
	char	*temp;
	int		size;

	size = 0;
	temp = ft_uitoa_base(number, define_base(option));
	if (!temp)
		exit(EXIT_FAILURE);
	if (option->upper)
		ft_strtoupper(temp);
	size += format_intoa(option, temp);
    ft_memdel((void **)&temp);
	return (size);
}
