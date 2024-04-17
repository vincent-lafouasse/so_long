#pragma once

#include "t_list/t_list.h"
#include "t_mlx.h"

void log_time(void);
void log_key_event(t_keycode);
void log_loop_event(void);

void log_str_lst(const t_list* strs);
