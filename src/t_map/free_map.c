#include <stdio.h>
#include <stdlib.h>
#include "t_map.h"

void free_map(t_map map)
{
    for (int row = 0; row < map.size.h; row++)
        printf("freeing row %d\n", row), free(map.data[row]);
    printf("freeing matrix\n");
    free(map.data);
    printf("freeing token list\n");
    ft_lstclear(&map.collectibles, NULL);
}
