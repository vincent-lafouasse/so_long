#include <stdio.h>
#include <stdlib.h>
#include "t_raw_map.h"

void free_map(t_raw_map map)
{
    for (int row = 0; row < map.size.h; row++)
        printf("freeing row %d\n", row), free(map.data[row]);
    printf("freeing matrix\n");
    free(map.data);
}
