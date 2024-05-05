#include <stdio.h>
#include <stdlib.h>
#include "geometry/t_position_list.h"
#include "libft/ft_io.h"
#include "libft/string.h"
#include "load/t_raw_map.h"
#include "log.h"
#include "parse_map.h"

char** deep_copy_map(const t_game* game);
bool is_walkable(t_position pos, const t_game* game);

bool is_reached(char** reached, t_position position, const t_game* game)
{
    if (!is_walkable(position, game))
        return false;
    return reached[position.y][position.x] == 'R';
}

void flood_fill(char** reached, t_position start, const t_game* game)
{
    printf("checking position\tx%d\ty%d\n", start.x, start.y);
    // log_char_matrix(g, t_dimension size)
    if (!is_walkable(start, game))
    {
        printf("pos is not walkable\n\n");
        return;
    }
    if (is_reached(reached, start, game))
    {
        printf("pos has already been reached\n\n");
        return;
    }
    reached[start.y][start.x] = 'R';
    printf("visited position\tx%d\ty%d\n\n", start.x, start.y);
    flood_fill(reached, position(start.x + 1, start.y), game);
    flood_fill(reached, position(start.x - 1, start.y), game);
    flood_fill(reached, position(start.x, start.y + 1), game);
    flood_fill(reached, position(start.x, start.y - 1), game);
}

bool has_valid_path(const t_game* game)
{
    ft_putstr_fd("checking for valid path\nmap\n", 1);
    log_char_matrix((const char**)game->board, game->size);
    ft_putstr_fd("\n", 1);
    char** reached = deep_copy_map(game);
    flood_fill(reached, game->player, game);
    if (!is_reached(reached, game->player, game))
        return false;
    if (!is_reached(reached, game->exit, game))
        return false;

    t_position_list* collectibles = game->collectibles;
    while (collectibles)
    {
        if (!is_reached(reached, collectibles->position, game))
            return false;
        collectibles = collectibles->next;
    }
    free_map((t_raw_map){reached, game->size});
    return true;
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

bool is_walkable(t_position pos, const t_game* game)
{
    if (pos.x >= game->size.w || pos.x < 0 || pos.y >= game->size.h ||
        pos.y < 0)
        return false;
    return game->board[pos.x][pos.y] != game->charset.WALL;
}
