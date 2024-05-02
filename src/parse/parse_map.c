#include "parse_map.h"
#include "error/error.h"

// must check for
// - enclosed in walls
// - at least one of each
// - existence of valid path

static bool map_is_enclosed_in_walls(const t_game* game, t_charset charset)
{
    for (int col = 0; col < game->size.w; col++)
    {
        if (game->board[0][col] != charset.WALL)
            return false;
        if (game->board[game->size.h - 1][col] != charset.WALL)
            return false;
    }
    for (int row = 0; row < game->size.h; row++)
    {
        if (game->board[row][0] != charset.WALL)
            return false;
        if (game->board[row][game->size.w - 1] != charset.WALL)
            return false;
    }
    return true;
}

static bool map_has_enough_tokens(const t_game* game, t_charset charset);
static void map_parse_tokens(t_game* t_charset);
static bool map_has_valid_path(const t_game* game, t_charset charset);

void parse_map(t_game* game, t_charset charset)
{
    if (!map_is_enclosed_in_walls(game, charset))
        free_game(game), die("Map is not enclosed in walls");
}
