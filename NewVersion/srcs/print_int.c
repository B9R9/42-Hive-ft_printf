#include "ft_printf.h"

// static int	set_lenght(t_parameter *option, char *str);
int	print_sign(t_parameter *option);

int	print_0x(t_parameter *option)
{
	int size;

	size = 0;
	if (option->conv == 'x')
	{
		if (option->upper)
			size += print_str("0X", ft_strlen("0X"));
		else
			size += print_str("0x", ft_strlen("0x"));
		option->flags = option->flags ^ F_HASHTAG;
	}
	else if (option->conv =='o')
	{
		size += print_char('0');
        option->flags = option->flags ^ F_HASHTAG;
	}
	return (size);
}

int	print_sign(t_parameter *option)
{
	int size;

	size = 0;
	if(option->flags & F_NEGATIF)
	{
		size += print_char('-');
		option->flags = option->flags ^ F_NEGATIF;
	}
	else if (option->flags & F_PLUS)
	{
		size += print_char ('+');
		option->flags = option->flags ^ F_PLUS;
	}
	return (size);
}

int	print_precision(int start, t_parameter *option, int lenght)
{
	int size;

    size = 0;
    while (start < (option->precision - lenght) && option->conv != 'f')
    {
        size += print_char('0');
        start++;
    }
    return (size);

}

void	set_lenght(t_parameter *option, char *str)
{
	int	to_remove;

	to_remove = 0;
	if (option->flags & F_HASHTAG)
	{
		if(option->conv == 'o')
			to_remove += 1;
		else
			to_remove += 2;
	}
	if (option->flags & F_NEGATIF || option->flags & F_PLUS)
		to_remove += 1;
	if(option->precision < (int)ft_strlen(str))
		option->precision = (int)ft_strlen(str);
	if (option->precision > option->width)
		option->width = 0;
	else
	{
		option->lenght = (option->width - to_remove) - option->precision;
		if (option->lenght < 0)
			option->lenght = 0;
	}
}

int	print_int(t_parameter *option, char *str)
{
	int	size;

	size = 0;
	// check_flasgbit(option);
	set_lenght(option, str);
	if (option->flags & F_MINUS)
		return (align(str,option));
	//lenght = set_lenght(option, str);
	if (option->flags & F_SPACE || \
	(!(option->flags & F_SPACE) && !(option->flags & F_ZERO) && option->width > 0))
	{
		while (size < option->lenght)
			size += print_char(' ');
		if (option->flags & F_HASHTAG)
			size += print_0x(option);
		if (option->flags & F_PLUS || option->flags & F_NEGATIF)
			size += print_sign(option);
		size += print_precision(0, option, (int)ft_strlen(str));
		size += print_str(str, (int)ft_strlen(str));
	}
	else
	{
		if (option->flags & F_HASHTAG)
			size += print_0x(option);
		if (option->flags & F_PLUS || option->flags & F_NEGATIF)
			size += print_sign(option);
		while (size < option->lenght)
			size += print_char('0');
		size += print_precision(0, option, (int)ft_strlen(str));
		size += print_str(str, (int)ft_strlen(str));
	}
	return (size);
}
