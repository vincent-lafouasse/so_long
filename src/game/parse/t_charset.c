#include "t_charset.h"
#include "libft/string.h"

t_charset default_charset(void)
{
    t_charset charset;
    charset.empty = '0';
    charset.wall = '1';
    charset.collectible = 'C';
    charset.exit = 'E';
    charset.player = 'P';
    return charset;
}

bool is_in_charset(char c, t_charset charset)
{
    return (charset.wall == c) || (charset.empty == c) ||
           (charset.player == c) || (charset.exit == c) ||
           (charset.collectible == c);
}
