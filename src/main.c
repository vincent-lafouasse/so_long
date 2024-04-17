#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <X11/keysym.h>

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"

#include "image.h"
#include "log.h"
#include "mlx.h"
#include "render.h"
#include "t_color.h"
#include "t_game.h"
#include "t_list/t_list.h"
#include "t_mlx.h"

#define WIDTH 600
#define HEIGHT 480
#define WINDOW_NAME ("idk, a name ig")

#define PLAYER_SPRITE_PATH "./assets/player.xpm"
#define MAP_PATH "./assets/maps/simple_map.ber"

#define IRRELEVANT_RETURN_VALUE 0

typedef struct
{
    t_game* game;
    t_mlx* mlx;
} t_update_input;

size_t ft_strlen(const char* s)
{
    size_t len = 0;

    while (*s)
    {
        s++;
        len++;
    }
    return len;
}

int update_game(t_keycode keycode, t_update_input* input)
{
    log_key_event(keycode);
    if (keycode == XK_Escape)
        mlx_loop_end(input->mlx->mlx);
    if (keycode == XK_p)
        mlx_string_put(input->mlx->mlx, input->mlx->window, 69, 420, RED,
                       "hello");
    if (keycode == XK_s)
        input->game->player_position.y += 32;
    input->game->needs_render = true;
    return IRRELEVANT_RETURN_VALUE;
}

void cleanup(t_mlx mlx);

void remove_trailing_newline(char* string)
{
    size_t len = ft_strlen(string);

    if (len == 0)
        return;

    if (string[len - 1] == '\n')
        string[len - 1] = '\0';
}

t_list* load_map_into_rev_list(const char* map_path)
{
    int fd = open(map_path, O_RDONLY);
    t_list* lines = NULL;
    t_list* current_node;
    char* line = get_next_line(fd);

    while (line)
    {
        remove_trailing_newline(line);
        current_node = ft_lstnew(line);
        ft_lstadd_front(&lines, current_node);
        line = get_next_line(fd);
    }

    close(fd);
    return lines;
}

void log_str_lst(const t_list* strs)
{
    while (strs)
    {
        printf("%s\n", (const char*)strs->content);
        strs = strs->next;
    }
}

char** map_list_to_array(const t_list* map_list, t_dimension* return_dim)
{
    size_t height = ft_lstsize((t_list*)map_list);
    return_dim->h = height;
    return_dim->w = ft_strlen(map_list->content);
    char** map = malloc(height * sizeof(char*));

    while (map_list)
    {
        map[height - 1] = map_list->content;
        height--;
        map_list = map_list->next;
    }

    return map;
}

int main(void)
{
    t_list* map_list = load_map_into_rev_list(MAP_PATH);
    // log_str_lst(map_list);

    t_dimension map_dimension;
    char** map = map_list_to_array(map_list, &map_dimension);

    for (int row = 0; row < map_dimension.h; row++)
    {
        printf("%s\n", map[row]);
    }

    const t_dimension window_size = dimension(WIDTH, HEIGHT);
    t_mlx mlx = init_mlx(window_size, WINDOW_NAME);
    t_image player_sprite = load_image_xpm(PLAYER_SPRITE_PATH, &mlx);

    t_image background = init_empty_image(window_size, &mlx);
    put_rectangle(&background, rectangle(position(0, 0), window_size), BLACK);

    t_rectangle rect = rectangle(position(5, 5), dimension(420, 69));

    t_game game = (t_game){NULL, dimension(0, 0), rect, position(69, 42), true};

    t_update_input update_input = (t_update_input){&game, &mlx};
    t_render_input render_input =
        (t_render_input){&mlx, &background, &player_sprite, &game};

    mlx_key_hook(mlx.window, &update_game, &update_input);
    // mlx_expose_hook(mlx.window, render, &render_input);
    mlx_loop_hook(mlx.mlx, &render, &render_input);
    mlx_loop(mlx.mlx);
    cleanup(mlx);
}

void cleanup(t_mlx mlx)
{
    // will cleanup sprites too, later tho
    mlx_destroy_window(mlx.mlx, mlx.window);
}
