#include "load/t_raw_map.h"
#include "parse/parse_map.h"
#include "t_game.h"

t_game init_game(const char* map_path, t_charset charset)
{
    t_game game;
    t_raw_map raw_map;

    raw_map = load_raw_map(map_path);
    game.board = raw_map.data;
    game.size = raw_map.size;
    game.charset = charset;
    game.n_collectibles = 0;
    parse_map(&game);
    game.done = false;
    return game;
}
