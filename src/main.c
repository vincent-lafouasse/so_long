#include <stdbool.h>
#include <unistd.h>
#include <X11/keysym.h>

#include "mlx.h"
#include "game/t_game.h"
#include "parse/t_charset.h"

#include "render/t_mlx.h"
#include "render/render.h"

#include "log/log.h"
#include "error/error.h"

#define WIDTH 600
#define HEIGHT 480
#define WINDOW_NAME ("idk, a name ig")

#define IRRELEVANT_RETURN_VALUE 0

typedef struct
{
    t_game* game;
    t_mlx* mlx;
} t_update_input;

typedef enum e_direction
{
    Up, Down, Left, Right,
} t_direction;

static bool is_wall(t_position pos, const t_game* game)
{
    return game->board[pos.y][pos.x] == game->charset.WALL;
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
    return true;
}

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
        try_move(Right, input->game);
    if (keycode == XK_d)
        try_move(Down, input->game);
    input->game->needs_render = true;
    return IRRELEVANT_RETURN_VALUE;
}

void cleanup(t_mlx mlx);

int main(int ac, char** av)
{
    if (ac != 2)
        die("Usage: ./so_long map.ber");

    t_game game = init_game(av[1], default_charset());

    const t_dimension window_size = dimension(WIDTH, HEIGHT);
    t_mlx mlx = init_mlx(window_size, WINDOW_NAME);

    t_update_input update_input = (t_update_input){&game, &mlx};
    t_render_input render_input = (t_render_input){&mlx, &game};

    mlx_key_hook(mlx.window, &update_game, &update_input);
    mlx_loop_hook(mlx.mlx, &render, &render_input);
    mlx_loop(mlx.mlx);

    cleanup(mlx);
    free_game(&game);
}

void cleanup(t_mlx mlx)
{
    // will cleanup sprites too, later tho
    // free_sprites(sprites) or something
    mlx_destroy_window(mlx.mlx, mlx.window);
}
