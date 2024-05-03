#include "geometry/t_position_list.h"
#include "libft/string.h"
#include "parse_map.h"
#include <stdlib.h>

char** deep_copy_map(const t_game* game);

t_position_list* find_neighbours(t_position pos, const t_game* game, t_charset charset)
{
    t_position_list* out = NULL;

    t_position candidates[4];
    ft_memcpy(&candidates, (t_position[]){
        position(pos.x + 1, pos.y),
        position(pos.x - 1, pos.y),
        position(pos.x, pos.y + 1),
        position(pos.x, pos.y - 1),
    }, sizeof(candidates));
}

// a classic bfs
// marks reached cells with a 'R'
char** reachable_cells(const t_game* game, t_charset charset)
{
    char** reached = deep_copy_map(game);
    t_position_list* queue = NULL;
    t_position_list* node;
    t_position current;
    t_position_list* neighbours;

    reached[game->player_position.x][game->player_position.y] = 'R';
    node = poslst_new(game->player_position);
    poslst_add_front(&queue, node);

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
