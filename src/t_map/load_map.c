#include "t_map.h"
#include <stdlib.h>

t_map load_map(const char* map_path)
{
    t_map map;
    (void)map_path;

    map.data = (char**)1;

    return map;
}

// `load_map` returns a map with NULL data if something failed
bool map_is_valid(t_map map)
{
    return map.data != NULL;
}
