#include <stdio.h>
#include <stdlib.h>
#include "error/error.h"
#include "t_map_internals.h"

t_map load_map_or_exit(const char* map_path)
{
    if (!str_ends_with(map_path, ".ber"))
        die("invalid map name");

    t_map map = load_raw_map_or_exit(map_path);

    parse_map(&map);

    return map;
}

bool map_is_valid(t_map map)
{
    return map.data != NULL;
}
