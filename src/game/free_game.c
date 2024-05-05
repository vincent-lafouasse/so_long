#include <stdio.h>
#include <stdlib.h>
#include "t_game.h"

void free_game(t_game* game)
{
    for (int row = 0; row < game->size.h; row++)
        printf("freeing row %d\n", row), free(game->board[row]);
    printf("freeing matrix\n");
    free(game->board);
    poslst_clear(&(game->collectibles));
}
