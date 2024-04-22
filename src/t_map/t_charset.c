#include "t_charset.h"
#include "libft/string.h"

t_charset default_charset(void)
{
    t_charset charset;
    ft_memcpy(&charset, DEFAULT_CHARSET, 5);
    return charset;
}
