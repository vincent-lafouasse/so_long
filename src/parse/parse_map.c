#include "parse_map.h"
#include <stddef.h>
#include "error/error.h"
#include "geometry/t_position_list.h"
#include "parse/t_charset.h"

// must check for
// - enclosed in walls
// - at least one of each
// - existence of valid path

static bool map_is_enclosed_in_walls(const t_game* game);
static bool map_has_enough_tokens(const t_game* game);
static void map_parse_tokens(t_game* game);

void parse_map(t_game* game)
{
    if (!map_is_enclosed_in_walls(game))
        free_game(game), die("Map is not enclosed in walls");
    if (!map_has_enough_tokens(game))
        free_game(game), die("Invalid map tokens");
    map_parse_tokens(game);
    if (position_compare(game->exit, position(0, 0)) == 0)
        free_game(game), die("Failed to parse map tokens");
    if (!has_valid_path(game))
        free_game(game), die("Map has unreachable tokens");
}

static bool map_is_enclosed_in_walls(const t_game* game)
{
    for (int col = 0; col < game->size.w; col++)
    {
        if (game->board[0][col] != game->charset.WALL)
            return false;
        if (game->board[game->size.h - 1][col] != game->charset.WALL)
            return false;
    }
    for (int row = 0; row < game->size.h; row++)
    {
        if (game->board[row][0] != game->charset.WALL)
            return false;
        if (game->board[row][game->size.w - 1] != game->charset.WALL)
            return false;
    }
    return true;
}

static bool map_has_enough_tokens(const t_game* game)
{
    size_t n_collectibles = 0;
    size_t n_exit = 0;
    size_t n_player = 0;
    char current;

    for (int row = 0; row < game->size.h; row++)
    {
        for (int col = 0; col < game->size.w; col++)
        {
            current = game->board[row][col];
            if (!is_in_charset(current, game->charset))
                return false;
            n_collectibles += (current == game->charset.COLLECTIBLE);
            n_exit += (current == game->charset.EXIT);
            n_player += (current == game->charset.PLAYER);
        }
    }
    return (n_exit == 1) && (n_player == 1) && (n_collectibles >= 1);
}

static void map_parse_tokens(t_game* game)
{
    char current;
    t_position_list* node;

    game->collectibles = NULL;
    for (int row = 0; row < game->size.h; row++)
    {
        for (int col = 0; col < game->size.w; col++)
        {
            current = game->board[row][col];
            if (current == game->charset.EXIT)
                game->exit = position(row, col);
            if (current == game->charset.PLAYER)
            {
                game->player = position(row, col);
                game->board[row][col] = game->charset.EMPTY;
            }
            if (current == game->charset.COLLECTIBLE)
            {
                node = poslst_new(position(row, col));
                if (!node)
                {
                    game->exit = position(0, 0);
                    return;
                }
                poslst_add_front(&(game->collectibles), node);
                game->board[row][col] = game->charset.EMPTY;
            }
        }
    }
}
