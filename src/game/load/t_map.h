#pragma once

#include <stdbool.h>

#include "geometry/geometry.h"

typedef struct
{
    char** data;
    t_dimension size;
} t_map;

// returns a map with NULL data if something failed
t_map load_map(const char* map_path);
void free_map(t_map map);
