#include "query_game.h"

bool is_player(t_position position, const t_game* game)
{
    return position_compare(position, game->player) == 0;
}

bool is_exit(t_position position, const t_game* game)
{
    return position_compare(position, game->exit) == 0;
}

bool is_collectible(t_position position, const t_game* game)
{
    t_position_node* current = game->collectibles.head;
    while (current)
    {
        if (position_eq(current->position, position))
            return true;
        current = current->next;
    }
    return false;
}

bool is_wall(t_position position, const t_game* game)
{
    return game->board[position.y][position.x] == game->charset.WALL;
}
