#include "ft_printf.h"

int		print_sign(t_parameter *option);
int		print_0x(t_parameter *option);
int		print_precision(int start, t_parameter *option, int lenght);
void	set_lenght(t_parameter *option, char *str);
int		print_int(t_parameter *option, char *str);

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
	if(option->precision < (int)ft_strlen(str) && option->conv != 'f')
		option->precision = (int)ft_strlen(str);
	if (option->flags & F_HASHTAG)
		to_remove += add_character_F_HASTAG(option->conv);
	if ((option->flags & F_NEGATIF || option->flags & F_PLUS) && \
	option->width >= option->precision)
		to_remove += 1;
	adjust_lenght(option, str, to_remove);
}

int	print_int(t_parameter *option, char *str)
{
	int	size;

	size = 0;
	set_lenght(option, str);
	if (option->flags & F_MINUS)
		return (align(str,option));
	if (option->flags & F_SPACE || \
	(!(option->flags & F_SPACE) && !(option->flags & F_ZERO) && option->width > 0))
		size += set_space(option);
	else
		size += set_zero(option);
	size += print_precision(0, option, (int)ft_strlen(str));
	if (!str)
		size += print_char('0');
	else
		size += print_str(str, (int)ft_strlen(str));
	return (size);
}
