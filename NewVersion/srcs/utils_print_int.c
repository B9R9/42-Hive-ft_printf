#include "ft_printf.h"

int		add_character_F_HASTAG(char conv);
int		set_space(t_parameter *option);
int		set_zero(t_parameter *option);
void	adjust_lenght(t_parameter *option, char *str, int to_remove);

int	add_character_F_HASTAG(char conv)
{
	if(conv == 'o')
		return (1);
	else
		return (2);
}

int	set_space(t_parameter *option)
{
	int	size;

	size = 0;
	while (size < option->lenght)
		size += print_char(' ');
	if (option->flags & F_HASHTAG)
		size += print_0x(option);
	if (option->flags & F_PLUS || option->flags & F_NEGATIF)
		size += print_sign(option);
	return (size);
}

int	set_zero(t_parameter *option)
{
	int size;

	size = 0;
	if (option->flags & F_HASHTAG)
		size += print_0x(option);
	if (option->flags & F_PLUS || option->flags & F_NEGATIF)
		size += print_sign(option);
	while (option->lenght > 0)
	{
		size += print_char('0');
		option->lenght -= 1;
	}
	return (size);
}

void	adjust_lenght(t_parameter *option, char *str, int to_remove)
{
	if (option->precision > option->width && option->conv != 'f')
		option->width = 0;
	else
	{
		option->lenght = (option->width - to_remove) - option->precision;
		if (option->lenght < 0)
			option->lenght = 0;
	}
	if (option->width == 0 && option->precision == (int)ft_strlen(str) && \
	option->flags & F_SPACE && (!(option->flags & F_NEGATIF) && \
	!(option->flags & F_PLUS)))
		option->lenght += 1;
	if (option->conv == 'u' && option->flags & F_HASHTAG && \
	option->width > option->precision)
		option->lenght += 2;
}
