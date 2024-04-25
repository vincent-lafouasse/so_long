#include "t_game.h"
#include <stddef.h>

t_game init_game(const char *map_path, t_charset charset)
{
    (void)map_path;
    (void)charset;
    t_game game;
    game.board = NULL;

    return game;
}
