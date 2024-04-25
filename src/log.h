#pragma once

#include "game/t_game.h"
#include "libft/t_list.h"
#include "t_mlx.h"

void log_time(void);
void log_key_event(t_keycode);
void log_loop_event(void);

void log_str_lst(const t_list* strs);
void log_char_matrix(const char** matrix, t_dimension size);
void log_game(t_game game);
