#include <stdlib.h>
#include "geometry/t_position_list.h"
#include "libft/string.h"
#include "parse_map.h"

char** deep_copy_map(const t_game* game);
bool is_walkable(t_position pos, const t_game* game, t_charset charset);
t_position_list* find_neighbours(t_position pos,
                                 const t_game* game,
                                 t_charset charset);
void set_as_reached(t_position pos, char** reached, t_dimension size);
bool is_reached(t_position pos, char** reached, t_dimension size);

// a classic bfs
// marks reached cells with a 'R'
char** reachable_cells(const t_game* game, t_charset charset)
{
    char** reached = deep_copy_map(game);
    t_position_list* queue = NULL;
    t_position current;
    t_position_list* neighbours;

    reached[game->player_position.x][game->player_position.y] = 'R';
    poslst_emplace_front(&queue, game->player_position);

    while (queue)
    {
        current = poslst_pop_back(&queue);
        neighbours = find_neighbours(current, game, charset);
        while (neighbours)
        {
            if (reached[neighbours->position.x][neighbours->position.y] != 'R')
            {
                reached[neighbours->position.x][neighbours->position.y] = 'R';
            }
        }
    }

    return reached;
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

t_position_list* find_neighbours(t_position pos,
                                 const t_game* game,
                                 t_charset charset)
{
    t_position_list* neighbours = NULL;
    t_position current;

    current = position(pos.x + 1, pos.y);
    if (is_walkable(current, game, charset))
        poslst_emplace_front(&neighbours, current);
    current = position(pos.x - 1, pos.y);
    if (is_walkable(current, game, charset))
        poslst_emplace_front(&neighbours, current);
    current = position(pos.x, pos.y + 1);
    if (is_walkable(current, game, charset))
        poslst_emplace_front(&neighbours, current);
    current = position(pos.x, pos.y - 1);
    if (is_walkable(current, game, charset))
        poslst_emplace_front(&neighbours, current);
    return neighbours;
}

bool is_walkable(t_position pos, const t_game* game, t_charset charset)
{
    if (pos.x >= game->size.w || pos.x < 0 || pos.y >= game->size.h ||
        pos.y < 0)
        return false;
    return game->board[pos.x][pos.y] != charset.WALL;
}

void set_as_reached(t_position pos, char** reached, t_dimension size)
{
    if (pos.x >= size.w || pos.x < 0 || pos.y >= size.h || pos.y < 0)
        return;
    reached[pos.x][pos.y] = 'R';
}

bool is_reached(t_position pos, char** reached, t_dimension size)
{
    if (pos.x >= size.w || pos.x < 0 || pos.y >= size.h || pos.y < 0)
        return false;
    return reached[pos.x][pos.y] == 'R';
}
