#include "libft.h"

t_bool	ft_isintneg(long long int number)
{
    if (1 / number > 0)
        return false;
    return true;
}
