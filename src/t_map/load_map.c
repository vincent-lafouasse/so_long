#include <stdio.h>
#include "error/error.h"
#include <stdlib.h>
#include "log.h"
#include "t_map_internals.h"

// `load_map` returns a map with NULL data if something failed
static t_map invalid_map(void);

void parse_map(t_map* map_return, t_list** map_list_ref); // next submodule


t_map load_map_or_exit(const char* map_path)
{
    if (!str_ends_with(map_path, ".ber"))
        die("invalid map name");

    t_map map = load_raw_map_or_exit(map_path);

    map.data = (char**)1;

    return map;
}

bool map_is_valid(t_map map)
{
    return map.data != NULL;
}

t_map invalid_map(void)
{
    t_map invalid;

    invalid.data = NULL;
    return invalid;
}

void parse_map(t_map* map_return, t_list** map_list_ref)
{
    (void)map_return;
    (void)map_list_ref;
    return;
}

