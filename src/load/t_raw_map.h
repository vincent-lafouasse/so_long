#pragma once

#include <stdbool.h>

#include "geometry/geometry.h"

typedef struct
{
    char** data;
    t_dimension size;
} t_raw_map;

// returns a map with NULL data if something failed
t_raw_map load_raw_map(const char* map_path);
void free_map(t_raw_map map);
