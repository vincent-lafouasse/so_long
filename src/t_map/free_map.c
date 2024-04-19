#include "t_map.h"
#include <stdlib.h>
#include <stdio.h>

void free_map(t_map map)
{
    for (int row = 0; row < map.size.h; row++)
        printf("freeing row %d\n", row), free(map.data[row]);
    free(map.data);
    
    // ft_lstclear(&map.collectibles)
}
