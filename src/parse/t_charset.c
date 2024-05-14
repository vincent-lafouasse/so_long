#include "t_charset.h"
#include "libft/string.h"

t_charset default_charset(void)
{
    t_charset charset;
    charset.EMPTY = '0';
    charset.WALL = '1';
    charset.COLLECTIBLE = 'C';
    charset.EXIT = 'E';
    charset.PLAYER = 'P';
    return charset;
}

bool is_in_charset(char c, t_charset charset)
{
    return (charset.WALL == c) || (charset.EMPTY == c) ||
           (charset.PLAYER == c) || (charset.EXIT == c) ||
           (charset.COLLECTIBLE == c);
}
