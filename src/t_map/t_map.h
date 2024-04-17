#pragma once

#include <stdbool.h>

#include "geometry/geometry.h"
#include "t_list/t_list.h"

typedef struct
{
    char** data;
    t_dimension size;
    t_position start;
    t_list* collectibles;
} t_map;

// returns a map with NULL data if something failed
t_map load_map(const char* map_path);

bool map_is_valid(t_map map);
