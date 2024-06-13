#include <stdlib.h>
#include "t_raw_map.h"

void free_map(t_raw_map map)
{
    for (int row = 0; row < map.size.h; row++)
        free(map.data[row]);
    free(map.data);
}
