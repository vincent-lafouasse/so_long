#include "update_game.h"
#include <X11/keysym.h>
#include "game/query_game.h"
#include "ft_printf.h"

#define IRRELEVANT_RETURN_VALUE 0

typedef enum e_direction
{
    Up,
    Down,
    Left,
    Right,
} t_direction;

bool try_move(t_direction direction, t_game* game);
void process_new_position(t_game* game);

void update_game(t_game* game, int keycode)
{
    if (keycode == XK_w)
        try_move(Up, game);
    if (keycode == XK_a)
        try_move(Left, game);
    if (keycode == XK_s)
        try_move(Down, game);
    if (keycode == XK_d)
        try_move(Right, game);
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
    {
        game->board[game->player.y][game->player.x] = game->charset.empty;
        game->n_collectibles -= 1;
    }
    if (game->n_collectibles == 0 && is_exit(game->player, game))
    {
        ft_printf("you have reached the exit\n");
        game->done = true;
    }
    game->move_count++;
    ft_printf("%zu\n", game->move_count);
}
