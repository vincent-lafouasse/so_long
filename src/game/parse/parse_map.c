#include "parse_map.h"
#include <stddef.h>
#include "error/error.h"
#include "game/query_game.h"
#include "t_charset.h"

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
    int col = 0;
    int row = 0;

    while (col < game->size.w)
    {
        if (!is_wall(position(col, 0), game))
            return false;
        if (!is_wall(position(col, game->size.h - 1), game))
            return false;
        col++;
    }
    while (row < game->size.h)
    {
        if (!is_wall(position(0, row), game))
            return false;
        if (!is_wall(position(game->size.w - 1, row), game))
            return false;
        row++;
    }
    return true;
}

static bool map_has_enough_tokens(const t_game* game)
{
    size_t n_collectibles = 0;
    size_t n_exit = 0;
    size_t n_player = 0;
    int row = 0;
    int col;

    while (row < game->size.h)
    {
        col = 0;
        while (col < game->size.w)
        {
            if (!is_in_charset(game->board[row][col], game->charset))
                return false;
            n_collectibles += is_collectible(position(col, row), game);
            n_exit += is_exit(position(col, row), game);
            n_player += is_player(position(col, row), game);
            col++;
        }
        row++;
    }
    return (n_exit == 1) && (n_player == 1) && (n_collectibles >= 1);
}

static void map_parse_tokens(t_game* game)
{
    char current;

	game->n_collectibles = 0;
    for (int row = 0; row < game->size.h; row++)
    {
        for (int col = 0; col < game->size.w; col++)
        {
            current = game->board[row][col];
            if (current == game->charset.EXIT)
            {
                game->exit = position(col, row);
                game->board[row][col] = game->charset.EMPTY;
            }
            if (current == game->charset.PLAYER)
            {
                game->player = position(col, row);
                game->board[row][col] = game->charset.EMPTY;
            }
            if (current == game->charset.COLLECTIBLE)
            {
                game->n_collectibles += 1;
            }
        }
    }
}
