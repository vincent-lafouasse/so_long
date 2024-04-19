#include "t_map.h"
#include <stdlib.h>

void free_map(t_map map)
{
    for (int row = 0; row < map.size.h; row++)
        free(map.data[row]);
    free(map.data);
    
    // ft_lstclear(&map.collectibles)
}
