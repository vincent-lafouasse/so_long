#include "parse_map.h"

// must check for 
// - enclosed in walls
// - at least one of each
// - existence of valid path

static bool map_is_enclosed_in_walls(const t_game* game, t_charset charset);
static bool map_has_enough_tokens(const t_game* game, t_charset charset);
static void map_parse_tokens(t_game* t_charset);
static bool map_has_valid_path(const t_game* game, t_charset charset);

void parse_map(t_game* game, t_charset charset)
{
    (void)game;
    (void)charset;
}
