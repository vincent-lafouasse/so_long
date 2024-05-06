#include <stdlib.h>
#include "t_game.h"

void free_game(t_game* game)
{
    for (int row = 0; row < game->size.h; row++)
        free(game->board[row]);
    free(game->board);
    poslst_clear(&(game->collectibles));
}
