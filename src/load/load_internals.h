#pragma once

#include "t_map.h"
#include "t_charset.h"

t_map load_raw_map_or_exit(const char* path);
void parse_map(t_map* map, t_charset charset);

// in string_utils.c
void trim_trailing_newline(char* s);
bool str_ends_with(const char* s, const char* pattern);
