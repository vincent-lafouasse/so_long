#pragma once

#include "geometry/geometry.h"
#include "t_list/t_list.h"

typedef struct
{
	char** data;
	t_dimension size;
	t_position start;
	t_list* collectibles;
} t_map;

t_map load_map(const char* map_path);
