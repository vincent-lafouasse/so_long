#include "load/t_raw_map.h"
#include "parse/parse_map.h"
#include "libft/string.h"
#include "t_game.h"

t_game init_game(const char *map_path, t_charset charset)
{
    t_game game;
    t_raw_map raw_map;

    raw_map = load_raw_map(map_path);
    ft_memcpy(&game, &raw_map, sizeof(raw_map));
    parse_map(&game, charset);
    return game;
}
