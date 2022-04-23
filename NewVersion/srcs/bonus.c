#include "ft_printf.h"

int	is_bonus(const char *s);
static t_bool	is_color(const char *s);
static t_bool	is_bold(const char *s);
static t_bool	is_blink(const char *s);
static t_bool	is_underline(const char *s);

static t_bool	is_underline(const char *s)
{
	if (!ft_strcmp(s, UNDERLINED) || !ft_strcmp(s, RESETUNDERLINED))
		return (true);
	return (false);
}

static t_bool	is_bold(const char *s)
{
	if (!ft_strcmp(s, BOLD) || !ft_strcmp(s, RESETBOLD))
		return (true);
	return (false);
}

static t_bool	is_blink(const char *s)
{
	if (!ft_strcmp(s, BLINK) || !ft_strcmp(s, RESETBLINK))
		return (true);
	return (false);
}

/*
** Receive s and check if s == a color
** Return True or False
*/
static t_bool	is_color(const char *s)
{
	if (!ft_strcmp(s, RED))
		return (true);
	if ( !ft_strcmp(s, DEFAULT))
		return (true);
	if ( !ft_strcmp(s, GREEN))
		return (true);
	if ( !ft_strcmp(s, YELLOW))
		return (true);
	if (!ft_strcmp(s, BLUE))
		return (true);
	if (!ft_strcmp(s, MAGENTA))
		return (true);
	if (!ft_strcmp(s, CYAN))
		return (true);
	if (!ft_strcmp(s, WHITE))
		return (true);
	return(false);
}


int	is_bonus(const char *s)
{
	if (is_color(s))
		return (true);
	if (is_underline(s))
		return (true);
	if (is_bold(s))
		return (true);
	if (is_blink(s))
		return (true);
	return (false);
}
