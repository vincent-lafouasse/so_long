#pragma once

#include "t_raw_map.h"

t_raw_map load_raw_map(const char* path);

// in string_utils.c
void trim_trailing_newline(char* s);
bool str_ends_with(const char* s, const char* pattern);