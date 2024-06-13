#include <stdio.h>
#include <stdlib.h>
#include "libft/string.h"
#include "game/load/t_raw_map.h"
#include "log/log.h"
#include "parse_map.h"

static void flood_fill(char** reached, t_position start, const t_game* game);
static bool is_walkable(t_position pos, const t_game* game);
static bool is_reached(char** reached, t_position position, const t_game* game);
static char** deep_copy_map(const t_game* game);

bool has_valid_path(const t_game* game)
{
    char** reached = deep_copy_map(game);
    flood_fill(reached, game->player, game);
    if (!is_reached(reached, game->player, game))
        return free_map((t_raw_map){reached, game->size}), false;
    if (!is_reached(reached, game->exit, game))
        return free_map((t_raw_map){reached, game->size}), false;

    int row = 0;
    int col;

    while (row < game->size.h)
    {
        col = 0;
        while (col < game->size.w)
        {
            if (game->board[row][col] == game->charset.COLLECTIBLE &&
                !is_reached(reached, position(col, row), game))
            {
                return free_map((t_raw_map){reached, game->size}), false;
            }
            col++;
        }
        row++;
    }
    free_map((t_raw_map){reached, game->size});
    return true;
}

void flood_fill(char** reached, t_position start, const t_game* game)
{
    if (!is_walkable(start, game))
    {
        return;
    }
    if (is_reached(reached, start, game))
    {
        return;
    }
    reached[start.y][start.x] = 'R';
    flood_fill(reached, position(start.x + 1, start.y), game);
    flood_fill(reached, position(start.x - 1, start.y), game);
    flood_fill(reached, position(start.x, start.y + 1), game);
    flood_fill(reached, position(start.x, start.y - 1), game);
}

bool is_reached(char** reached, t_position position, const t_game* game)
{
    if (!is_walkable(position, game))
        return false;
    return reached[position.y][position.x] == 'R';
}

bool is_walkable(t_position pos, const t_game* game)
{
    if (pos.x >= game->size.w || pos.x < 0 || pos.y >= game->size.h ||
        pos.y < 0)
        return false;
    return game->board[pos.y][pos.x] != game->charset.WALL;
}

char** deep_copy_map(const t_game* game)
{
    char** copy = malloc(sizeof(char*) * game->size.h);

    for (int row = 0; row < game->size.h; row++)
    {
        copy[row] = ft_strdup(game->board[row]);
    }
    return copy;
}
