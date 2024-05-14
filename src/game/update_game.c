#include "update_game.h"
#include "log/log.h"
#include <X11/keysym.h>

#define IRRELEVANT_RETURN_VALUE 0

typedef enum e_direction
{
    Up, Down, Left, Right,
} t_direction;

static bool is_wall(t_position pos, const t_game* game);
bool is_collectible(t_position position, const t_game* game);
bool is_exit(t_position position, const t_game* game);

bool try_move(t_direction direction, t_game* game);
void process_new_position(t_game* game);

int update_game(t_keycode keycode, t_update_input* input)
{
    log_key_event(keycode);
    if (keycode == XK_Escape)
        mlx_loop_end(input->mlx->mlx);
    if (keycode == XK_w)
        try_move(Up, input->game);
    if (keycode == XK_a)
        try_move(Left, input->game);
    if (keycode == XK_s)
        try_move(Down, input->game);
    if (keycode == XK_d)
        try_move(Right, input->game);
    input->game->needs_render = true;
    return IRRELEVANT_RETURN_VALUE;
}

bool try_move(t_direction direction, t_game* game)
{
    t_position new_position = game->player;

    if (direction == Up)
        new_position.y -= 1;
    else if (direction == Down)
        new_position.y += 1;
    else if (direction == Left)
        new_position.x -= 1;
    else if (direction == Right)
        new_position.x += 1;
    else
        return false;
    if (is_wall(new_position, game))
        return false;
    game->player = new_position;
    process_new_position(game);
    return true;
}

void process_new_position(t_game* game)
{
    if (is_collectible(game->player, game))
        poslst_remove(&(game->collectibles), game->player);
    if (!game->collectibles && is_exit(game->player, game))
        game->done = true;
}

static bool is_wall(t_position pos, const t_game* game)
{
    return game->board[pos.y][pos.x] == game->charset.WALL;
}
