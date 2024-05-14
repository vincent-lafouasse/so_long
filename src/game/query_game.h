#pragma once

#include "t_game.h"

bool is_wall(t_position position, const t_game* game);
bool is_player(t_position position, const t_game* game);
bool is_exit(t_position position, const t_game* game);
bool is_collectible(t_position position, const t_game* game);
