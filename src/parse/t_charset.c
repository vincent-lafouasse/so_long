#include "t_charset.h"
#include "libft/string.h"

t_charset default_charset(void)
{
    t_charset charset;
    ft_memcpy(&charset, DEFAULT_CHARSET, 5);
    return charset;
}

bool is_in_charset(char c, t_charset charset)
{
    return (charset.WALL == c) || (charset.EMPTY == c) ||
           (charset.PLAYER == c) || (charset.EXIT == c) ||
           (charset.COLLECTIBLE == c);
}
